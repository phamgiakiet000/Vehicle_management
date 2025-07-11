// Midterm_PhamNguyenGiaKiet_21110051.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<vector>
#include <string>
using namespace std;
class Vehicle {
protected:
    
    string brand;
    string model;
    string year;
    float dailyRentalCost;
    bool rent=false;
    
public:
    
    Vehicle(string brand, string model, string year, float dailyCost) {
        this->brand = brand;
        this->model = model;
        this->year = year;
        this->dailyRentalCost = dailyCost;
    
    
    };
    //create new vehicle
    void getVehicleInfo() {
        cout << "\n\n\t Please enter the brand of Vehicle: ";
        cin >> brand;
        cout << "\n\n\t Please enter the model of Vehicle: ";
        cin >> model;
        cout << "\n\n\t Please enter the year of Vehicle: ";
        cin >> year;
        cout << "\n\n\t Please enter the dailyRentalCost of Vehicle: ";
        cin >> dailyRentalCost;
        

    }
    string getBrand() {
        return this->brand;
    }
    string getModel() {
        return this->model;
    }
    float getCost() {
        return this->dailyRentalCost;
    }
    //show vehicle
    virtual void putVehicle() const{
        cout << "\n\n\t  the brand of Vehicle: ";
        cout << brand;
        cout << "\n\n\t  the model of Vehicle: ";
        cout << model;
        cout << "\n\n\t  the year of Vehicle: ";
        cout << year;
        cout << "\n\n\t  the dailyRentalCost of Vehicle: ";
        cout << dailyRentalCost;
    }
    void rentVehicle() {
        this->rent = true;
    }
    void returnRent() {
        this->rent = false;
    }
    bool isRented() const { return rent; }
};

//A.Demonstrate Inheritance
class Car :public Vehicle {
private:
    int seats;
public:
    
    Car(const string &brand,const string &model,const string &year,const float &dailyRentalCost, int seats):Vehicle(brand,model,year,dailyRentalCost) ,seats(seats){
        
    };
    // B.Demonstrate Polymorphism
    void putVehicle() const override {
        Vehicle::putVehicle();
        cout << "\n\n\t Number of seats: ";
        cout << seats;
        cout << endl;
    }
};
class Truck :public Vehicle {
private:
    float cargoCapacity;
public:
    Truck(const string& brand, const string& model, const string& year, const float& dailyRentalCost, float cargoCapacity) :Vehicle(brand, model, year, dailyRentalCost), cargoCapacity(cargoCapacity) {

    };
    //B.Demonstrate Polymorphism
    void putVehicle() const override {
        Vehicle::putVehicle();
        cout << "\n\n\t Number of cargoCapacity: ";
        cout << cargoCapacity;
        cout << endl;
    }
};
class Motorcycle :public Vehicle {
private:
    float extraMoneyPerEngine;
public:
    Motorcycle(const string& brand, const string& model, const string& year, const float& dailyRentalCost, float extraMoneyPerEngine) :Vehicle(brand, model, year, dailyRentalCost), extraMoneyPerEngine(extraMoneyPerEngine) {

    };
    // B.Demonstrate Polymorphism
    void putVehicle() const override {
        Vehicle::putVehicle();
        cout << "\n\n\t Number of extraMoneyPerEngine: ";
        cout << extraMoneyPerEngine;
        cout << endl;
    }
};

class Customer {
private:
    string CustomerId;
    string name;
    string contactDetails;
    bool renting = false;
    vector<string> history;
public:
    Customer( string name, string contactDetails) {
        this->name = name;
        this->contactDetails = contactDetails;
        this->CustomerId = name + contactDetails;
    }
    void goRent(string Vehicle,string carBrand,string totalCost ) {
        this->renting = true;
        string tmp = "\n\n\tCar type: " + Vehicle + "  ,Car model: " + carBrand + " , totalCost:"+totalCost;
        history.push_back(tmp);
    }
    void returnRent() {
        this->renting = false;
    }
    bool stateRent() {
        return this->renting;
    }
    void DisplayHistory() {
        cout << "\tDisplaying History ...\n\n";
        if (history.size() == 0) {
            cout << "\tNo History for transaction";
            cout<< "\t================";
            return;
        }

        for (string s : history) {
            
            cout << "\t" << s << "\n\n";
            cout << endl;
            
        }
        cout << endl;
        cout << "==========================================\n\n";
    }
    void displayInfor() {
        cout << "\tCustomer ID : " << this->CustomerId << endl;
        cout << "\tCustomer name : " << this->name << endl;
        cout << "\tCustomer Balance : " << this->contactDetails << "\n\n";
        cout << endl;
    }
};
class VehicleManagement {
private :
    
    
public:
    //Use dynamic memory allocation
    vector<Customer*> customers;
    vector<Vehicle*> vehicles;

    void addCustomer(Customer* customer) {
        customers.push_back(customer);
    }
    void addVehicle(Vehicle* vehicle) {
        vehicles.push_back(vehicle);
    }
    void displayAvailableVehicles() {
        std::cout << "Available Vehicles:\n";
        for (size_t i = 0; i < vehicles.size(); i++) {
            if (!vehicles[i]->isRented()) {
                std::cout << "Vehicle " << i + 1 << ": ";
                vehicles[i]->putVehicle();
            }
        }
    }
    bool rentVehicle(int vehicleIndex,int customerNumber,int day) {
        if (vehicleIndex < 0 || static_cast<size_t>(vehicleIndex) >= vehicles.size()) {
            return false;
        }
        Vehicle* vehicle = vehicles[vehicleIndex];
        Customer* customer = customers[customerNumber];
        if (!vehicle->isRented()&& !customer->stateRent()) {
            vehicle->rentVehicle();
            float costPerDay = day * vehicle->getCost();
            customer->goRent(vehicle->getBrand(),vehicle->getModel(),to_string(costPerDay));
            cout << "You have rented the following vehicle:\n";
            vehicle->putVehicle();
            return true;
        }
        
        

        return false;
    }
    
    void displayHistoryofCustomer() {
        cout << "Available Vehicles:\n";
        
        for (size_t i = 0; i < customers.size(); i++) {
                customers[i]->displayInfor();
                cout << "Customer " << i + 1 << ": ";
                customers[i]->DisplayHistory();
            
            cout << endl;
        }
        
    }
    
    bool returnVehicle(int vehicleIndex) {
        if (vehicleIndex < 0 || static_cast<size_t>(vehicleIndex) >= vehicles.size()) {
            return false;
        }
        Vehicle* vehicle = vehicles[vehicleIndex];
        if (vehicle->isRented()) {
            vehicle->returnRent();
            cout << "You have returned the following vehicle:\n";
            vehicle->putVehicle();
            return true;
        }
        return false;
    }

};
int main()
{
    cout << "Hello World!\n";
    VehicleManagement vehicleManagement;
    //Use pointer
    Customer* custom1 = new Customer("PhamNguyenGiaKiet", "0934050603");
    Customer* custom2 = new Customer("LeNguyenDaThao", "0704506743");
    Car* car1=new Car("Toyota", "Camry", "2020", 550.0, 5);
    Car* car2 = new Car("Honda", "Civic", "2023", 500.0, 5);
    Motorcycle* motor1=new  Motorcycle("Honda", "vario", "2021", 100.0, 150);
    Motorcycle* motor2 = new  Motorcycle("Honda", "Sh", "2023", 200.0, 350);
    Truck* truck1=new Truck("Ford", "F-150", "2019", 600.0, 2.5);

    vehicleManagement.addCustomer(custom1);
    vehicleManagement.addCustomer(custom2);
    vehicleManagement.addVehicle(car1);
    vehicleManagement.addVehicle(car2);
    vehicleManagement.addVehicle(motor1);
    vehicleManagement.addVehicle(motor2);
    vehicleManagement.addVehicle(truck1);

    int choice;
    do {
        cout << "Rental Vehicle Management System\n";
        cout << "1. Display available vehicles\n";
        cout << "2. Rent a vehicle\n";
        cout << "3. Return a vehicle\n";
        cout << "4. Return a customer History\n";
        cout << "5. Quit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            vehicleManagement.displayAvailableVehicles();
            break;
        case 2:
            int rentIndex;
            int customerNumber;
            int day;
            cout << "Enter the index of the vehicle you want to rent: ";
            cin >> rentIndex;
            cout << "Enter the customer number for rent car ";
            cin >> customerNumber;
            cout << "Enter the day for rent car ";
            cin >> day;
            if (!vehicleManagement.rentVehicle((rentIndex - 1),(customerNumber-1),day)) {
                cout << "Invalid selection or the vehicle is already rented.\n";
            }
            break;
        case 3:
            int returnIndex;
            cout << "Enter the index of the vehicle you want to return: ";
            cin >> returnIndex;
            if (!vehicleManagement.returnVehicle(returnIndex - 1)) {
                cout << "Invalid selection or the vehicle is not rented.\n";
            }
            break;
        case 4:
            vehicleManagement.displayHistoryofCustomer();
            break;

        case 5:
            cout << "Exiting the program.\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);

    // Clean up: release memory allocated for vehicles
    for (Vehicle* vehicle : vehicleManagement.vehicles) {
        delete vehicle;
    }

    return 0;
    

}

