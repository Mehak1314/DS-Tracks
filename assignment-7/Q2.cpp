// Improved version → Finds both minimum and maximum each pass → sorts from both ends.
#include <iostream>
using namespace std;

void improvedSelectionSort(int arr[], int n) {
    int start = 0, end = n - 1;

    while (start < end) {
        int minIndex = start, maxIndex = start;

        // Find both min and max in current range
        for (int i = start; i <= end; i++) {
            if (arr[i] < arr[minIndex])
                minIndex = i;
            if (arr[i] > arr[maxIndex])
                maxIndex = i;
        }

        // Swap minimum element with start
        swap(arr[start], arr[minIndex]);

        // If max element was at start, it moved due to previous swap
        if (maxIndex == start)
            maxIndex = minIndex;

        // Swap maximum element with end
        swap(arr[end], arr[maxIndex]);

        // Move inward
        start++;
        end--;
    }
}

int main() {
    int arr[] = {5, 2, 9, 1, 5, 6, 7, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    improvedSelectionSort(arr, n);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    return 0;
}
