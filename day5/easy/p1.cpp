#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int minimumMoves(const vector<int>& seats, const vector<int>& students) {
    int n = seats.size();
    vector<int> sortedSeats(seats);
    sort(sortedSeats.begin(), sortedSeats.end());
    vector<int> sortedStudents(students);
    sort(sortedStudents.begin(), sortedStudents.end());

    int moves = 0;
    for (int i = 0; i < n; ++i) {
        moves += abs(sortedSeats[i] - sortedStudents[i]);
    }
    return moves;
}
int main() {
    vector<int> seats = {3, 1, 5};
    vector<int> students = {2, 7, 4};
    int result = minimumMoves(seats, students);
    cout << "Minimum moves required: " << result << endl;
    return 0;
}