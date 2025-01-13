#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int countStudents(vector<int>& students, vector<int>& sandwiches) {
    queue<int> studentQueue(students.begin(), students.end());
    queue<int> sandwichQueue(sandwiches.begin(), sandwiches.end());
    int count = 0; 
    int initialQueueSize = studentQueue.size(); 
    while (!studentQueue.empty() && count < initialQueueSize) { 
        if (studentQueue.front() == sandwichQueue.front()) {
            studentQueue.pop();
            sandwichQueue.pop();
            count = 0; // Reset count if a student eats a sandwich
        } else {
            studentQueue.push(studentQueue.front());
            studentQueue.pop();
            count++;
        }
    }
    return studentQueue.size();
}
int main() {
    vector<int> students = {1, 1, 0, 0};
    vector<int> sandwiches = {0, 1, 0, 1};
    int numStudentsUnableToEat = countStudents(students, sandwiches);
    cout << numStudentsUnableToEat << endl; 
    return 0;
}