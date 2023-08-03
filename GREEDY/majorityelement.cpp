#include <bits/stdc++.h>
#include <iostream>
using namespace std;

// below is the method using pointers and O(1)space 
// using map it will take o(n)space 

class Solution{
  public:
     // Function to find majority element in the array
    // a: input array
    // size: size of input array
    int majorityElement(int arr[], int size)
    {
        
        int count = 1;
        int res = 0;
        for(int i = 1 ; i < size ; i++){
            if(arr[i]== arr[res]){
                count++;
            }
            else {
                count--;
            }
            if(count == 0){
                count = 1;
                res = i;
            }
        }
          count = 0;
          for(int i = 0 ; i < size ; i++){
              if(arr[res]==arr[i]){
                  count++;
              }
          }
          if(count >size/2)return arr[res];
          else return -1;
        
    }

};


// using map 


//User function template for C++

// class Solution{
//   public:
    
//     int majorityElement(int a[], int size)
//     {
        
//         unordered_map<int , int>mp;
//         for(int i = 0 ; i < size ; i++){
//             mp[a[i]]++;
//         }
//         int freq = 0;
//         int ele;
//         for(auto it : mp){
//             if(it.second > size/2){
//               return it.first;
//             }
//         }
//         return -1;
        
//     }
// };