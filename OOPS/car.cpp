#include <bits/stdc++.h> 
#include <iostream>
using namespace std;

class Car {
    public:
    int noOfGear;
    string color;
            Car(int noOfGear , string color)
        {
            this->noOfGear = noOfGear;
            this->color = color;
        }

 
   void printCarInfo(){
        cout << "noOfGear: "<<this->noOfGear << endl;
        cout << "color: " << this-> color<< endl;
        
    }
};

class RaceCar: public Car {
public:
int maxSpeed;
public:
RaceCar(int noOfGear, string color ,int maxSpeed):Car(noOfGear , color){
    this->maxSpeed = maxSpeed;
}
    void printInfo(){
        printCarInfo();
        cout << "maxSpeed: "<< this->maxSpeed << endl;
    }

};

int main() {
    int noOfGear, maxSpeed;
    string color;
    cin >> noOfGear >> color >> maxSpeed;
    RaceCar raceCar(noOfGear, color, maxSpeed);
    raceCar.printInfo();
    return 0;
}



