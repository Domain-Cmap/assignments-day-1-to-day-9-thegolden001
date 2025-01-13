#include <iostream>
#include <stack>
#include <climits>
using namespace std;
class MinStack {
    stack<int> mainStack;
    stack<int> minStack;

public:
    MinStack() {
        minStack.push(INT_MAX);
    }

    void push(int val) {
        mainStack.push(val);
        minStack.push(min(val, minStack.top()));
    }

    void pop() {
        mainStack.pop();
        minStack.pop();
    }

    int top() {
        return mainStack.top();
    }

    int getMin() {
        return minStack.top();
    }
};

int main() {
    MinStack minStack;

    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);
    cout << "Minimum element: " << minStack.getMin() << endl; 
    minStack.pop();
    cout << "Top element: " << minStack.top() << endl;       
    cout << "Minimum element: " << minStack.getMin() << endl; 
    minStack.push(5);
    minStack.push(3);
    cout << "Minimum element after pushing 5 and 3: " << minStack.getMin() << endl; 

    return 0;
}
