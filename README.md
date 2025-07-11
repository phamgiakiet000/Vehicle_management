 ## Overview

This application is a simplified Vehicle Rental Management System designed to manage the rental of various vehicle types, including cars, trucks, and motorcycles. It is built using object-oriented programming (OOP) principles in C++ and includes a UML class diagram to illustrate the class hierarchy and relationships.

## How the App Works





Initialization: The system starts by initializing a Vehicle Rental Management object that manages collections of Customer and Vehicle objects.



Vehicle Types: The system supports three derived vehicle classes (Car, Truck, Motorcycle) inheriting from a base Vehicle class. Each vehicle type has common attributes (brand, model, year, daily rental cost) and specific attributes (seats for Car, cargo capacity for Truck, engine displacement for Motorcycle).



Customer Management: Customers are managed with unique IDs, names, and contact details. Each customer can rent only one vehicle at a time, and the vehicle becomes unavailable until returned.



Rental Process:





Customers can rent a vehicle using the goRent method.



The rental cost is calculated by adding the daily rental cost with additional costs based on vehicle-specific attributes (e.g., passenger capacity for cars).



Vehicles are returned using the returnRent method, making them available again.



Operations: The system provides methods to add customers and vehicles, display available vehicles, track rental history, and calculate total rental costs.



Test Scenario: The app includes hardcoded instances of 2 customers and 5 vehicles (2 cars, 1 truck, 2 motorcycles) to simulate rental transactions, including a 2-day car rental for the first customer.

## Usage





Replace the first customer's information with your personal details as noted in the test scenario.



Compile and run the C++ code to simulate the rental management system.



Use the provided methods to perform rental operations and view results.

## Notes

This project demonstrates OOP concepts such as inheritance, polymorphism, abstraction, and dynamic memory allocation.
