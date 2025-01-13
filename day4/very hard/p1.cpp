#include <iostream>
#include <stack>
#include <vector>
using namespace std;
int poisonousPlants(vector<int>& p) {
    int n = p.size();
    vector<int> days(n, 0); 
    stack<int> stk;
    
    for (int i = 0; i < n; ++i) {
        while (!stk.empty() && p[i] <= p[stk.top()]) {
            stk.pop();
        }

        if (!stk.empty()) {
            days[i] = days[stk.top()] + 1;
        }

        stk.push(i);
    }
    return *max_element(days.begin(), days.end());
}

int main() {
    int n;
    cin >> n;
    vector<int> p(n);
    
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
    }
    cout << poisonousPlants(p) << endl;
    return 0;
}
