#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    vector<vector<int>> graph(numCourses);
    vector<int> inDegree(numCourses, 0), result;
    queue<int> q;
    
    for (auto& prereq : prerequisites) {
        graph[prereq[1]].push_back(prereq[0]);
        ++inDegree[prereq[0]];
    }
    
    for (int i = 0; i < numCourses; ++i) {
        if (inDegree[i] == 0) {
            q.push(i);
        }
    }
    
    while (!q.empty()) {
        int course = q.front();
        q.pop();
        result.push_back(course);
        for (int next : graph[course]) {
            --inDegree[next];
            if (inDegree[next] == 0) {
                q.push(next);
            }
        }
    }
    
    return result.size() == numCourses ? result : vector<int>();
}
int main() {
    int numCourses = 4;
    vector<vector<int>> prerequisites = {{1, 0}, {2, 0}, {3, 1}, {3, 2}};
    vector<int> order = findOrder(numCourses, prerequisites);
    
    if (order.empty()) {
        cout << "No valid course order" << endl;
    } else {
        for (int course : order) {
            cout << course << " ";
        }
        cout << endl;
    }
    return 0;
}
