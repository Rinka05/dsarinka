#include<bits/stdc++.h>
#include <iostream>
#include <map>
#include<unordered_map>
using namespace std;





int main(){
    unordered_map<string, int>mp;
    
   //insertion ke do tareeke
   pair<string,int>p = make_pair("rinka" , 153);
   mp.insert(p);

   mp["yashi"] = 91;
 


 

 // searching
 cout <<mp["yashi"]<< endl;
 cout << mp.at("rinka")<< endl;
 cout << mp.at("unknown")<< endl;
 // above line gives error
 //below line outputs zeero as it creates a entry for the unknown key
 cout << mp["unknown"]<< endl;
     return 0;

}
