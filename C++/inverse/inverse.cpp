#include <iostream>
#include <vector>

using namespace std;

// =============================================================================
// Primodial function
// =============================================================================

using Matrix = vector<vector<double>>;

Matrix Zeros(int rows, int cols);
Matrix Minor(Matrix M, int p, int q);
double Det(Matrix M);
Matrix Inverse(Matrix M);

// =============================================================================
// Main function
// =============================================================================

int main() {
    int i;
    Matrix A = Zeros(2, 2);
    A[0][0] = 1;
    A[0][1] = 2;
    A[1][0] = 3;
    A[1][1] = 4;

    double D = Det(A);
    Matrix B = Inverse(A);

    cout << D << endl;

    for (i=0; i<2;i++) {
        for (int j=0; j<2;j++) {
            switch (j) {
                case 1:
                cout << B[i][j] << endl;
                break;
                default:
                cout << B[i][j] << "\t";
                break;
            }
        }
    }

    return 0;
}

// =============================================================================
// Sub Functions
// =============================================================================

Matrix Zeros(int rows, int cols) {
    Matrix A(rows, vector<double>(cols, 0));
    return A;
}

Matrix Inverse(Matrix M) {
    int rows = M.size();
    int cols = M[0].size();
    Matrix A = Zeros(rows, cols);
    int i,j;
    
    for (i=0;i<rows;i++) {
        for (j=0;j<cols;j++) {
            switch ((i+j)%2) {
                case 0:
                A[i][j] = Det(Minor(M, j, i)) / Det(M);
                break;
                case 1:
                A[i][j] = -Det(Minor(M,j,i)) / Det(M);
                break;
            }
        }
    }
    return A;
}

Matrix Minor(Matrix M, int p, int q) {
    int rows = M.size() - 1;
    int cols = M[0].size() - 1;
    int i, j;
    Matrix A = Zeros(rows, cols);
    
    for (i=0;i<rows;i++) {
        for (j=0;j<cols;j++) {
            if (i < p && j < q) {
                A[i][j] = M[i][j];
            } else if (i < p && j >= q) {
                A[i][j] = M[i][j+1];
            } else if (i >= p && j < q) {
                A[i][j] = M[i+1][j];
            } else {
                A[i][j] = M[i+1][j+1];
            }
        }
    }

    return A;
}

double Det(Matrix M) {
    int rows = M.size();
    int cols = M[0].size();

    if (rows == 1 || cols == 1) {
        return M[0][0];
    }

    int i;
    double s = 0.;

    for (i=0;i<cols;i++) {
        switch (i%2) {
            case 0:
            s += M[0][i] * Det(Minor(M, 0, i));
            break;
            case 1:
            s -= M[0][i] * Det(Minor(M, 0, i));
            break;
        }
    }
    return s;
}