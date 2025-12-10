(homework:C++:B3) Write the C-language program equivalent to the C++ code below. The code must be able to be used by different cars, e.g. "Jane's car" vs "Jack's car". Note: The purpose is not to reproduce OOP in C but just to have the C program produce the same outputs given the same inputs/actions.



#include <iostream> 
// From geeksforgeeks: Object Oriented Programming in C++
﻿using namespace std;
 
// Abstract class Vehicle
class Vehicle {
public:
 
    // Abstract methods 
    virtual void accelerate() = 0;
    
    // pure virtual function
    virtual void brake() = 0;       
 
    void startEngine() {
        cout << "Engine started!" << endl;
    }
};
 
class Car : public Vehicle {
public:
 
    // Implement abstract methods
    void accelerate() override {
        cout << "Car: Pressing gas pedal..." << endl;
    }
 
    void brake() override {
        cout << "Car: Applying brakes..." << endl;
        
    }
};
 
int main() {
    
    // Create object using pointer to abstract class
    Vehicle* myCar = new Car();  
    myCar->startEngine();
    myCar->accelerate();
    myCar->brake();
 
    delete myCar; 
    return 0;
}
