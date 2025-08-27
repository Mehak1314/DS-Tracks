#include <iostream>
using namespace std;
// Linear Search
int linearSearch(int arr[], int n, int target) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == target) {
            return i; // return index if found
        }
    }
    return -1; // not found
}

// Binary Search (Iterative)
int binarySearch(int arr[], int n, int target) {
    int low = 0, high = n - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2; // prevents overflow

        if (arr[mid] == target)
            return mid;
        else if (arr[mid] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return -1; // not found
}

int main() {
    // Sorted array for Binary Search
    int arr[] = {2, 5, 8, 12, 16, 23, 38, 45, 56, 72, 91};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 23;

    // Linear Search
    int linResult = linearSearch(arr, n, target);
    if (linResult != -1)
        cout << "Linear Search: Element found at index " << linResult << endl;
    else
        cout << "Linear Search: Element not found" << endl;

    // Binary Search
    int binResult = binarySearch(arr, n, target);
    if (binResult != -1)
        cout << "Binary Search: Element found at index " << binResult << endl;
    else
        cout << "Binary Search: Element not found" << endl;

    return 0;
}
