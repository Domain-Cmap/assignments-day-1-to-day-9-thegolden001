#include <iostream>
#include <stack>
using namespace std;
class MyQueue {
private:
    stack<int> stkInput;
    stack<int> stkOutput;

    void move() {
        if (stkOutput.empty()) {
            while (!stkInput.empty()) {
                stkOutput.push(stkInput.top());
                stkInput.pop();
            }
        }
    }
public:
    MyQueue() {}

    void push(int x) {
        stkInput.push(x);
    }

    int pop() {
        move();
        int front = stkOutput.top();
        stkOutput.pop();
        return front;
    }

    int peek() {
        move();
        return stkOutput.top();
    }

    bool empty() {
        return stkInput.empty() && stkOutput.empty();
    }
};
int main() {
    MyQueue myQueue;
    myQueue.push(1);
    myQueue.push(2);
    cout << myQueue.peek() << endl;
    cout << myQueue.pop() << endl;  
    cout << myQueue.empty() << endl; 
    myQueue.push(3);
    myQueue.push(5);
    myQueue.push(7);
    cout << myQueue.peek() << endl; 
    cout << myQueue.pop() << endl;  
    cout << myQueue.peek() << endl; 
    cout << myQueue.empty() << endl; 
    return 0;
}
