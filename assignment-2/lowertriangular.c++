#include <iostream>
using namespace std;

// Function to print the lower triangular matrix from 1D storage
void LowerTriangularMatrix(int a[], int n)
{
    int k = 0;
    cout << "\nThe lower triangular matrix is:\n";
    for (int i = 0; i < n; i++)  // rows
    {
        for (int j = 0; j < n; j++)  // cols
        {
            if (i >= j)  // lower triangle (including diagonal)
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
    cout << "Enter size of lower triangular matrix: ";
    cin >> n;

    int size = n * (n + 1) / 2;   // number of non-zero elements
    int *A = new int[size];       // 1D array

    cout << "Enter elements row by row (only lower part):\n";
    int k = 0;
    for (int i = 0; i < n; i++)      // row
    {
        for (int j = 0; j <= i; j++) // col (only lower part)
        {
            cin >> A[k++];
        }
    }

    // Print matrix
    LowerTriangularMatrix(A, n);

    delete[] A;
    return 0;
}
