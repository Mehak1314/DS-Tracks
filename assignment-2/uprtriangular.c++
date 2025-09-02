#include <iostream>
using namespace std;

// Function to print upper triangular matrix from 1D storage
void UpperTriangularMatrix(int a[], int n)
{
    int k = 0;
    cout << "\nThe upper triangular matrix is:\n";
    for (int i = 0; i < n; i++)  // rows
    {
        for (int j = 0; j < n; j++)  // columns
        {
            if (i <= j)  // upper triangle including diagonal
                cout << a[k++] << " ";
            else
                cout << "0 ";
        }
        cout << endl;
    }
}

int main()
{
    int n;
    cout << "Enter size of upper triangular matrix: ";
    cin >> n;

    int size = n * (n + 1) / 2;   // number of non-zero elements
    int *A = new int[size];       // 1D array

    cout << "Enter elements row by row (only upper part):\n";
    int k = 0;
    for (int i = 0; i < n; i++)        // row
    {
        for (int j = i; j < n; j++)    // only upper part
        {
            cin >> A[k++];
        }
    }

    // Print matrix
    UpperTriangularMatrix(A, n);

    delete[] A;
    return 0;
}
