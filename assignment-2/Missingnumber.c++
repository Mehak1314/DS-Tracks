#include <iostream>
using namespace std;

// Linear Approach
int findMissingLinear(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        if(arr[i]!=(i+1)){
            return i+1;
        }   
    }
    return n;
}

// Binary Search Approach
int findMissingBinary(int arr[], int n) {
    int low = 0, high = n - 2; // array has n-1 elements
    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] == mid + 1) {
            // Left side correct → search in right half
            low = mid + 1;
        } else {
            // Mismatch → missing number is in left half
            high = mid - 1;
        }
    }
    return low + 1; // missing number
}

int main() {
    int arr[] = {1, 2, 3, 5, 6, 7};
    int n = 7; // numbers should be 1 to 7

    cout << "Missing Number (Linear): " << findMissingLinear(arr, n) << endl;
    cout << "Missing Number (Binary Search): " << findMissingBinary(arr, n) << endl;
    return 0;
}
