#include <iostream>
#include <bits/stdc++.h>
using namespace std;


class complexx{
private:
int real;
int imaginary;


public:
complexx(int real , int imaginary){
    this-> real = real ;
    this->imaginary = imaginary;
}

void print(){
    cout << this->real << " "<< "+"<< " "<< 'i' << this->imaginary ;
}
void add(complexx c2){
    int first = this->real + c2.real;
    int second = this->imaginary+c2.imaginary;
   this->real = first;
    this->imaginary = second;
}
void multiply(complexx c2){
    int first = ((this->real *c2.real)-(this->imaginary*c2.imaginary));
    int second = ((this->imaginary*c2.real)+(this->real*c2.imaginary));
    this->real = first;
    this->imaginary= second;
}

};