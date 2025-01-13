#include <iostream>
#include <string>
using namespace std;

class Employee {
protected:
    string name;
    int id;
    double salary;
public:
    Employee(string n, int i, double s) : name(n), id(i), salary(s) {}
    virtual void calculateEarnings() = 0;
};

class Manager : public Employee {
private:
    int rating;
public:
    Manager(string n, int i, double s, int r) : Employee(n, i, s), rating(r) {}
    void calculateEarnings() override {
        double bonus = salary * (rating * 0.10);
        cout << "Employee: " << name << " (ID: " << id << ")\n"
             << "Role: Manager\n"
             << "Base Salary: " << salary << "\n"
             << "Bonus: " << bonus << "\n"
             << "Total Earnings: " << salary + bonus << endl;
    }
};

class Developer : public Employee {
private:
    int extraHours;
public:
    Developer(string n, int i, double s, int e) : Employee(n, i, s), extraHours(e) {}
    void calculateEarnings() override {
        double overtime = extraHours * 500;
        cout << "Employee: " << name << " (ID: " << id << ")\n"
             << "Role: Developer\n"
             << "Base Salary: " << salary << "\n"
             << "Overtime Compensation: " << overtime << "\n"
             << "Total Earnings: " << salary + overtime << endl;
    }
};

int main() {
    int type;
    cout << "Enter Employee Type (1 for Manager, 2 for Developer): ";
    cin >> type;

    string name;
    int id, rating, extraHours;
    double salary;

    cout << "Enter Name, ID, and Salary: ";
    cin >> name >> id >> salary;

    if (type == 1) {
        cout << "Enter Performance Rating (1-5): ";
        cin >> rating;
        Manager m(name, id, salary, rating);
        m.calculateEarnings();
    } else if (type == 2) {
        cout << "Enter Extra Hours Worked: ";
        cin >> extraHours;
        Developer d(name, id, salary, extraHours);
        d.calculateEarnings();
    } else {
        cout << "Invalid employee type." << endl;
    }

    return 0;
}
