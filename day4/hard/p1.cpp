#include <iostream>
#include <vector>
using namespace std;
int maxSi(vector<int>& A, int L, int R) {
    int n = A.size();
    if (L < 0 || R >= n || L > R) {
        return -1; 
    }
    int M1 = INT_MAX, M2 = INT_MAX; 

    for (int i = L; i <= R; ++i) {
        M1 = min(M1, A[i]); 
        if (M1 == M2) { 
            M2 = max(M2, A[i]); 
        }
    }
    if (M1 == M2) {
        return -1; 
    }
    return ((M1 ^ M2) | (M1 & M2)) ^ (M1 & M2);
}
int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    int L, R;
    cin >> L >> R;
    int result = maxSi(A, L - 1, R - 1); 
    if (result != -1) {
        cout << result << endl;
    } else {
        cout << "Invalid input or no distinct smallest elements" << endl;
    }
return 0;
}