#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

// =============================================================================
// Primodial function
// =============================================================================

vector<vector<double>> Matrix(int, int);
vector<vector<double>> Minor(vector<vector<double>>);
double Determinant(vector<vector<double>>);
vector<vector<double>> Inverse(vector<vector<double>>);

// =============================================================================
// Main function
// =============================================================================

int main() {
    int i;
    vector<vector<double>> A = Matrix(2, 2);
    A[0][0] = 1;
    A[0][1] = 2;
    A[1][0] = 3;
    A[1][1] = 4;

    vector<vector<double>> B = Inverse(A);

    for (i=0; i<2;i++) {
        for (int j=0; j<2;j++) {
            switch (j) {
                case 1:
                cout << B[i][j] << endl;
                break;
                default:
                cout << B[i][j] << "\t" << endl;
                break;
            }
        }
    }

    for (i=0; i<2;i++) {
        delete[] A[i];
        delete[] B[i];
    }

    return 0;
}

// =============================================================================
// Sub Functions
// =============================================================================

vector<vector<double>> Matrix(int rows, int cols) {
    vector<vector<double>> A(5, vector<double>(5, 0));
    return A;
}