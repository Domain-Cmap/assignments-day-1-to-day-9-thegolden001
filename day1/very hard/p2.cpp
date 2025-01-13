#include <iostream>
#include <string>
using namespace std;

class Vehicle {
protected:
    string brand;
    string model;
    double mileage;
public:
    Vehicle(string b, string m, double mi) : brand(b), model(m), mileage(mi) {}
    virtual void display() = 0;
};

class Car : public Vehicle {
protected:
    double fuel;
    double distance;
public:
    Car(string b, string m, double mi, double f, double d) : Vehicle(b, m, mi), fuel(f), distance(d) {}
    void display() override {
        double fuelEfficiency = distance / fuel;
        cout << "Vehicle: " << brand << " " << model << "\n"
             << "Mileage: " << mileage << "\n"
             << "Fuel Efficiency: " << fuelEfficiency << " miles/gallon" << endl;
    }
};

class ElectricCar : public Car {
private:
    double batteryCapacity;
    double efficiency;
public:
    ElectricCar(string b, string m, double mi, double f, double d, double bc, double e)
        : Car(b, m, mi, f, d), batteryCapacity(bc), efficiency(e) {}

    void display() override {
        double range = batteryCapacity * efficiency;
        cout << "Vehicle: " << brand << " " << model << "\n"
             << "Mileage: " << mileage << "\n"
             << "Range: " << range << " miles" << endl;
    }
};

int main() {
    int type;
    cout << "Enter Vehicle Type (1 for Car, 2 for Electric Car): ";
    cin >> type;

    string brand, model;
    double mileage, fuel, distance, batteryCapacity, efficiency;

    cout << "Enter Brand, Model, and Mileage: ";
    cin >> brand >> model >> mileage;

    if (type == 1) {
        cout << "Enter Fuel (gallons) and Distance Covered (miles): ";
        cin >> fuel >> distance;
        Car c(brand, model, mileage, fuel, distance);
        c.display();
    } else if (type == 2) {
        cout << "Enter Fuel (gallons), Distance Covered (miles), Battery Capacity (kWh), and Efficiency (miles per kWh): ";
        cin >> fuel >> distance >> batteryCapacity >> efficiency;
        ElectricCar ec(brand, model, mileage, fuel, distance, batteryCapacity, efficiency);
        ec.display();
    } else {
        cout << "Invalid vehicle type." << endl;
    }

    return 0;
}
