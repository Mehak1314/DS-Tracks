#include <iostream>
using namespace std;

struct Element {
    int row, col, val;
};

int main() {
    Element A[20], B[20], C[40];  // triplet matrices
    int n1, n2;

    // Input first matrix
    cout << "Enter rows, cols, non-zero elements of A: ";
    cin >> A[0].row >> A[0].col >> A[0].val;
    n1 = A[0].val;
    cout << "Enter row col value for A:\n";
    for (int i = 1; i <= n1; i++) {
        cin >> A[i].row >> A[i].col >> A[i].val;
    }

    // Input second matrix
    cout << "Enter rows, cols, non-zero elements of B: ";
    cin >> B[0].row >> B[0].col >> B[0].val;
    n2 = B[0].val;
    cout << "Enter row col value for B:\n";
    for (int i = 1; i <= n2; i++) {
        cin >> B[i].row >> B[i].col >> B[i].val;
    }

    // Check dimensions
    if (A[0].row != B[0].row || A[0].col != B[0].col) {
        cout << "Matrices cannot be added!\n";
        return 0;
    }

    // Addition (merge process)
    C[0].row = A[0].row;
    C[0].col = A[0].col;

    int i = 1, j = 1, k = 1;
    while (i <= n1 && j <= n2) {
        if (A[i].row < B[j].row ||
            (A[i].row == B[j].row && A[i].col < B[j].col)) {
            C[k++] = A[i++];
        }
        else if (B[j].row < A[i].row ||
                 (B[j].row == A[i].row && B[j].col < A[i].col)) {
            C[k++] = B[j++];
        }
        else { // Same position -> add values
            C[k] = A[i];
            C[k].val = A[i].val + B[j].val;
            k++;
            i++;
            j++;
        }
    }

    // Copy remaining elements
    while (i <= n1) C[k++] = A[i++];
    while (j <= n2) C[k++] = B[j++];

    C[0].val = k - 1; // update count

    // Print result
    cout << "\nResult of A + B (Triplet Form):\n";
    cout << "Row Col Val\n";
    for (int p = 0; p <= C[0].val; p++) {
        cout << C[p].row << " " << C[p].col << " " << C[p].val << endl;
    }

    return 0;
}
