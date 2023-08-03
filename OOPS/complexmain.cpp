#include <iostream>
#include <bits/stdc++.h>
using namespace std;


#include "Complex.cpp"


int main(){
    int nature ; cin >> nature ;
    complexx c1(4 ,5);
    complexx c2(6,7);
  if(nature == 1){
    c1.add(c2);
  }
  else {
    c1.multiply(c2);
  }
  c1.print();
}