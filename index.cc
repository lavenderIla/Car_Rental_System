#include <iostream>
#include <iomanip> // Input and output formatting
using namespace std;

// Base Class: Vehicle
class Vehicle {
protected:
    string model;
    string make;
    int year;
    double price_per_day;
    bool availability;

public:
    // Default Constructor
    Vehicle()
        : model("Unknown"), make("Unknown"), year(0), price_per_day(0.0), availability(false) {}

    // Parameterized Constructor
    Vehicle(string mod, string mk, int yr, double price, bool avail)
        : model(mod), make(mk), year(yr), price_per_day(price), availability(avail) {}

    void getDetails();        // Input vehicle details
    void displayDetails();    // Display vehicle details
    double calculateRentalCost(int days); // Calculate rental cost
};

// Derived Class: Car (Public Derivation)
class Car : public Vehicle {
    string fuel_type;
    int seating_capacity;

public:
    // Default Constructor
    Car() : Vehicle(), fuel_type("Unknown"), seating_capacity(0) {}

    // Parameterized Constructor
    Car(string mod, string mk, int yr, double price, bool avail, string fuel, int seating)
        : Vehicle(mod, mk, yr, price, avail), fuel_type(fuel), seating_capacity(seating) {}

    void getCarDetails();
    void displayCarDetails();
};

// Derived Class: Truck (Public Derivation)
class Truck : public Vehicle {
    double cargo_capacity; // tons
    int maximum_load;      // kg

public:
    // Default Constructor
    Truck() : Vehicle(), cargo_capacity(0.0), maximum_load(0) {}

    // Parameterized Constructor
    Truck(string mod, string mk, int yr, double price, bool avail, double cargo, int load)
        : Vehicle(mod, mk, yr, price, avail), cargo_capacity(cargo), maximum_load(load) {}

    void getTruckDetails();
    void displayTruckDetails();
};

// Implementation of Vehicle class methods
void Vehicle::getDetails() {
    cout << "\nEnter vehicle model: ";
    cin >> model;
    cout << "Enter vehicle make: ";
    cin >> make;
    cout << "Enter manufacturing year: ";
    cin >> year;
    cout << "Enter price per day: $";
    cin >> price_per_day;
    cout << "Is the vehicle available (1 for Yes, 0 for No)? ";
    cin >> availability;
}

void Vehicle::displayDetails() {
    cout << "Vehicle Model: " << setw(10) << model << endl;
    cout << "Vehicle Make: " << setw(10) << make << endl;
    cout << "Year: " << setw(10) << year << endl;
    cout << "Price per Day: $" << setw(10) << price_per_day << endl;
    cout << "Availability: " << setw(10) << (availability ? "Yes" : "No") << endl;
}

double Vehicle::calculateRentalCost(int days) {
    return price_per_day * days;
}

// Implementation of Car class methods
void Car::getCarDetails() {
    getDetails();
    cout << "Enter fuel type (Petrol, Diesel, Electric): ";
    cin >> fuel_type;
    cout << "Enter seating capacity: ";
    cin >> seating_capacity;
}

void Car::displayCarDetails() {
    displayDetails();
    cout << "Fuel Type: " << setw(10) << fuel_type << endl;
    cout << "Seating Capacity: " << setw(10) << seating_capacity << endl;
}

// Implementation of Truck class methods
void Truck::getTruckDetails() {
    getDetails();
    cout << "Enter cargo capacity (in tons): ";
    cin >> cargo_capacity;
    cout << "Enter maximum load (in kg): ";
    cin >> maximum_load;
}

void Truck::displayTruckDetails() {
    displayDetails();
    cout << "Cargo Capacity: " << setw(10) << cargo_capacity << " tons" << endl;
    cout << "Maximum Load: " << setw(10) << maximum_load << " kg" << endl;
}

// Main Function
int main() {
    while (true) {
        int choice;
        cout << "\nChoose vehicle type to add:\n";
        cout << "1. Car\n";
        cout << "2. Truck\n";
        cout << "3. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            Car car;
            car.getCarDetails();
            cout << "\nCar Details Entered:\n";
            car.displayCarDetails();

            int rental_days;
            cout << "\nEnter number of days to rent the car: ";
            cin >> rental_days;
            cout << "Rental cost for the car: $" << car.calculateRentalCost(rental_days) << endl;

        } else if (choice == 2) {
            Truck truck;
            truck.getTruckDetails();
            cout << "\nTruck Details Entered:\n";
            truck.displayTruckDetails();

            int rental_days;
            cout << "\nEnter number of days to rent the truck: ";
            cin >> rental_days;
            cout << "Rental cost for the truck: $" << truck.calculateRentalCost(rental_days) << endl;

        } else if (choice == 3) {
            cout << "Exiting program. Goodbye!" << endl;
            break;
        } else {
            cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
