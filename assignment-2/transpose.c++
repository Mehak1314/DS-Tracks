#include<iostream>
using namespace std;
struct Element{
    int row, col, val;
};
int main(){
    int n;  // number of non-zero elements
    Element A[20], T[20];

    // Input sparse matrix
    cout << "Enter rows, cols, non-zero elements: ";
    cin >> A[0].row >> A[0].col >> A[0].val;
    n = A[0].val;

    cout << "Enter row, col, value for each non-zero element:\n";
    for (int i = 1; i <= n; i++) {
        cin >> A[i].row >> A[i].col >> A[i].val;
    }

    // Transpose logic
    T[0].row = A[0].col;
    T[0].col = A[0].row;
    T[0].val = A[0].val;

    for (int i = 1; i <= n; i++) {
        T[i].row = A[i].col;   // swap row and col
        T[i].col = A[i].row;
        T[i].val = A[i].val;
    }

    // Print original
    cout << "\nOriginal Sparse Matrix (Triplet Form):\n";
    cout << "Row Col Val\n";
    for (int i = 0; i <= n; i++) {
        cout << A[i].row << " " << A[i].col << " " << A[i].val << endl;
    }

    // Print transpose
    cout << "\nTranspose Sparse Matrix (Triplet Form):\n";
    cout << "Row Col Val\n";
    for (int i = 0; i <= n; i++) {
        cout << T[i].row << " " << T[i].col << " " << T[i].val << endl;
    }

    return 0;
}