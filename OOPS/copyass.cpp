#include <bits/stdc++.h>
#include <iostream>
using namespace std ;

class student{
   public:
   int rollnumber;
   int age ;
   student(int r , int a){
    this->rollnumber = r ;
    this->age = a;
   }
   void display(){
    cout <<"rollnumber"<< this->rollnumber << endl;
    cout <<"age"<< this->age << endl;
   }

};



int main(){

  student s1(1001 , 10);
  student s2(1005 , 20);
  student *s3 = new student(1009 , 30);
  s1.display();
  s2.display();
  s2 = s1;
  // dynamically created objects are copied by derefrencing
  *s3 = s1;
  




  
}