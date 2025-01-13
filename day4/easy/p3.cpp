#include <iostream>
#include <stack>
#include <vector>
using namespace std;
vector<int> asteroidCollision(vector<int>& asteroids) {
    stack<int> st;

    for (int asteroid : asteroids) {
        bool collided = false;
        while (!st.empty() && asteroid < 0 && st.top() > 0) {
            if (abs(asteroid) > st.top()) {
                st.pop();
            } else if (abs(asteroid) < st.top()) {
                collided = true;
                break;
            } else {
                st.pop();
                collided = true;
                break;
            }
        }
        if (!collided) {
            st.push(asteroid);
        }
    }
    vector<int> result;
    while (!st.empty()) {
        result.push_back(st.top());
        st.pop();
    }
    reverse(result.begin(), result.end());

    return result;
}
int main() {
    vector<int> asteroids = {5, 10, -5};
    vector<int> result = asteroidCollision(asteroids);
    for (int asteroid : result) {
        cout << asteroid << " ";
    }
    cout << endl; 

    return 0;
}