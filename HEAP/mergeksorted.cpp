#include <bits/stdc++.h>
#include <iostream>
using namespace std ;

vector<int>mergekarrays(vector<vector<int>*>input ){
    vector<int>finalans ;
    priority_queue<int , vector<int>, greater<int>>p;
    for(int i = 0 ; i < input.size();i++){
        for(int j = 0 ; j < input[i]->size(); j++){
            p.push(input[i]->at(j));
        }
    }
    while(!p.empty()){
        finalans.push_back(p.top());
        p.pop();

    }
    return finalans;
}



int main(){
    int k ; cin >> k ;
    vector<vector<int>*>input ;
    for(int i = 1 ; i <= k ; i++){
        int size ; cin>> size;
        vector<int>*current = new vector<int>;
    for(int j = 0 ; j < size ; j++){
        int a ; cin >> a ;
        current->push_back(a);
    }
    input.push_back(current);
    }
   vector<int>output = mergekarrays(input);
  for(int i = 0 ; i < output.size(); i++){
    cout << output[i]<< " ";
  }
  cout << "\n";
  return 0;
}