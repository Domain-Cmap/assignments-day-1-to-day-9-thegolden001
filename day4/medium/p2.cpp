#include <iostream>
using namespace std;
void reverseQueue(queue<int>& q) {
    if (q.empty()) {
        return;
    }
    int data = q.front();
    q.pop();
    reverseQueue(q);
    q.push(data);
}
int main() {
    queue<int> q;
    q.push(5);
    q.push(24);
    q.push(9);
    q.push(6);
    q.push(8);
    q.push(4);
    q.push(1);
    q.push(8);
    q.push(3);
    q.push(6);
    reverseQueue(q);
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
    return 0;
}