#include <iostream>
using namespace std;

struct Element {
    int row, col, val;
};

int main() {
    int n1, n2; // non-zero counts
    Element A[20], B[20], C[50];

    // Input A
    cout << "Enter rows, cols, non-zero for Matrix A: ";
    cin >> A[0].row >> A[0].col >> A[0].val;
    n1 = A[0].val;

    cout << "Enter row col val for A:\n";
    for (int i = 1; i <= n1; i++) {
        cin >> A[i].row >> A[i].col >> A[i].val;
    }

    // Input B
    cout << "Enter rows, cols, non-zero for Matrix B: ";
    cin >> B[0].row >> B[0].col >> B[0].val;
    n2 = B[0].val;

    cout << "Enter row col val for B:\n";
    for (int i = 1; i <= n2; i++) {
        cin >> B[i].row >> B[i].col >> B[i].val;
    }

    // Check multiplication possibility
    if (A[0].col != B[0].row) {
        cout << "Multiplication not possible!\n";
        return 0;
    }

    // Multiply
    int k = 1; // index for C
    for (int i = 1; i <= n1; i++) {
        for (int j = 1; j <= n2; j++) {
            if (A[i].col == B[j].row) {
                // Possible multiplication
                int r = A[i].row;
                int c = B[j].col;
                int v = A[i].val * B[j].val;

                // Check if (r,c) already exists in C → add
                bool found = false;
                for (int x = 1; x < k; x++) {
                    if (C[x].row == r && C[x].col == c) {
                        C[x].val += v;
                        found = true;
                        break;
                    }
                }

                // If not found, insert new entry
                if (!found) {
                    C[k].row = r;
                    C[k].col = c;
                    C[k].val = v;
                    k++;
                }
            }
        }
    }

    // Store result dimensions
    C[0].row = A[0].row;
    C[0].col = B[0].col;
    C[0].val = k - 1;

    // Print result
    cout << "\nResultant Matrix (Triplet Form):\n";
    cout << "Row Col Val\n";
    for (int i = 0; i < k; i++) {
        cout << C[i].row << " " << C[i].col << " " << C[i].val << endl;
    }

    return 0;
}
