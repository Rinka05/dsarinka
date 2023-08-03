#include <bits/stdc++.h>
#include <iostream>
using namespace std;

// check if array represents max or min heap

bool ismaxheap(int *arr , int n , int index){
    int leftchildindex = 2*index+1;
    int rightchildindex = 2*index+2;
    if(index>=n/2){
        return true ;
    }
    while(leftchildindex <n ||rightchildindex<n){
        if(arr[index]>arr[leftchildindex]&&arr[index]>arr[rightchildindex]&&(ismaxheap(arr , n , leftchildindex)&&ismaxheap(arr , n , rightchildindex))){
            return true ;
        }
        else {
            return false ;
        }
    }

}

int main(){
    int n ; cin >> n ; 
    int *arr = new int[n];
    for(int i = 0 ; i < n ; i++){
       cin >>arr[i];
    }
     cout << (ismaxheap(arr , n , 0)?"True":"false") << endl;
        delete []arr;
        return 0;
}






