#include <iostream>
#include <vector>
using namespace std;

void operate(const vector<vector<int>>& A, const vector<vector<int>>& B, int operation) {
    int m = A.size();
    int n = A[0].size();
    int p = B[0].size();
    
    if (operation == 1) { // Matrix Addition
        if (A.size() == B.size() && A[0].size() == B[0].size()) {
            vector<vector<int>> result(m, vector<int>(n));
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    result[i][j] = A[i][j] + B[i][j];
                }
            }
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    cout << result[i][j] << " ";
                }
                cout << endl;
            }
        } else {
            cout << "Invalid dimensions for operation." << endl;
        }
    } else if (operation == 2) { // Matrix Multiplication
        if (A[0].size() == B.size()) {
            vector<vector<int>> result(m, vector<int>(p, 0));
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < p; j++) {
                    for (int k = 0; k < n; k++) {
                        result[i][j] += A[i][k] * B[k][j];
                    }
                }
            }
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < p; j++) {
                    cout << result[i][j] << " ";
                }
                cout << endl;
            }
        } else {
            cout << "Invalid dimensions for operation." << endl;
        }
    } else {
        cout << "Invalid operation." << endl;
    }
}

int main() {
    int m, n, p, operation;
    cout << "Enter dimensions of Matrix A (m n): ";
    cin >> m >> n;
    cout << "Enter dimensions of Matrix B (n p): ";
    cin >> n >> p;
    
    vector<vector<int>> A(m, vector<int>(n));
    vector<vector<int>> B(n, vector<int>(p));

    cout << "Enter elements of Matrix A:" << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> A[i][j];
        }
    }

    cout << "Enter elements of Matrix B:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < p; j++) {
            cin >> B[i][j];
        }
    }

    cout << "Enter operation (1 for addition, 2 for multiplication): ";
    cin >> operation;

    operate(A, B, operation);

    return 0;
}
