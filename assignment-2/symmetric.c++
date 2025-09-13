#include <iostream>
using namespace std;

// Function to print symmetric matrix from 1D storage
void SymmetricMatrix(int a[], int n)
{
    cout << "\nThe symmetric matrix is:\n";
    for (int i = 0; i < n; i++)  // rows
    {
        for (int j = 0; j < n; j++)  // cols
        {
            if (i >= j)  // element stored in lower triangle
            {
                int index = (i * (i + 1)) / 2 + j; 
                cout << a[index] << " ";
            }
            else  // mirror from lower triangle
            {
                int index = (j * (j + 1)) / 2 + i;
                cout << a[index] << " ";
            }
        }
        cout << endl;
    }
}

int main()
{
    int n;
    cout << "Enter size of symmetric matrix: ";
    cin >> n;

    int size = n * (n + 1) / 2;   // number of unique elements
    int *A = new int[size];       // 1D array

    cout << "Enter elements row by row (lower triangular part):\n";
    int k = 0;
    for (int i = 0; i < n; i++)        // row
    {
        for (int j = 0; j <= i; j++)   // only lower part
        {
            cin >> A[k++];
        }
    }

    // Print symmetric matrix
    SymmetricMatrix(A, n);

    delete[] A;
    return 0;
}
