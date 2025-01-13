#include <iostream>
using namespace std;

double salary(double stipend) {
    return stipend;
}

double salary(double baseSalary, double bonuses) {
    return baseSalary + bonuses;
}

double salary(double baseSalary, double bonuses, double incentives) {
    return baseSalary + bonuses + incentives;
}

int main() {
    double stipend, baseSalary, bonuses, incentives;

    cout << "Enter stipend for Intern: ";
    cin >> stipend;

    cout << "Enter base salary and bonuses for Regular Employee: ";
    cin >> baseSalary >> bonuses;

    cout << "Enter base salary, bonuses, and incentives for Manager: ";
    cin >> baseSalary >> bonuses >> incentives;

    cout << "Intern Salary: " << salary(stipend) << endl;
    cout << "Employee Salary: " << salary(baseSalary, bonuses) << endl;
    cout << "Manager Salary: " << salary(baseSalary, bonuses, incentives) << endl;

    return 0;
}
