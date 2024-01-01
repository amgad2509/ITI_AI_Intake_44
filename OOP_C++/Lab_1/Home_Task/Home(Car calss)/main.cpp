#include <iostream>
#include<string.h>

using namespace std;

class Car {
private:
    char name[15];
    char model[20];
    int year;
    int price;

public:
    // Getter methods to access attributes
    char* getName()
    {
        return name;
    }

    char* getModel()
    {
        return model;
    }

    int getYear()
    {
        return year;
    }

    int getPrice()
    {
        return price;
    }

    // Setter methods to modify attributes
    void setName(char* newName) {
        strcpy(name, newName);
    }

    void setModel(char* newModel) {
        strcpy(model, newModel);
    }

    void setYear(int newYear) {
        year = newYear;
    }

    void setPrice(int newPrice) {
        price = newPrice;
    }

    // Behavior: Display car information
    void displayInfo(){
        cout << "Name: " << name << endl;
        cout << "Model: " << model << endl;
        cout << "Year: " << year << endl;
        cout << "Price: $" << price << endl;
    }
};

int main() {
    // Create a Car object and set its attributes using setter methods
    Car myCar;
    myCar.setName("Toyota");
    myCar.setModel("Camry");
    myCar.setYear(2022);
    myCar.setPrice(25000);

    // Display car information using the class method
    myCar.displayInfo();

    // Modify car attributes using setter methods
    myCar.setPrice(26000);
    myCar.setYear(2023);

    // Display the updated car information
    myCar.displayInfo();

    return 0;
}
