#include <iostream>
#include <string>
using namespace std;
int calPoints(string ops[], int n) {
    int record[n];  
    int size = 0;  
    for (int i = 0; i < n; ++i) {
        string op = ops[i];
        if (op == "+") {
            record[size] = record[size - 1] + record[size - 2];
            ++size;
        } else if (op == "D") {
            record[size] = 2 * record[size - 1];
            ++size;
        } else if (op == "C") {
            --size;
        } else {
            record[size] = stoi(op);  
            ++size;
        }
    }
    int total = 0;
    for (int i = 0; i < size; ++i) {
        total += record[i];
    }
    return total;
}

int main() {
    string ops1[] = {"5", "2", "C", "D", "+"};
    int n1 = 5;
    cout << calPoints(ops1, n1) << endl;  
    string ops2[] = {"5", "-2", "4", "C", "D", "9", "+", "+"};
    int n2 = 8;
    cout << calPoints(ops2, n2) << endl;  
    return 0;
}
