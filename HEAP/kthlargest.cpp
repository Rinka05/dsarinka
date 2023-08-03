#include <bits/stdc++.h>
#include <iostream>
using namespace std ;


int kthlargest(int *arr , int n , int k ){
   priority_queue <int>p;
   for(int i = 0 ; i < n  ; i++){
    p.push(arr[i]);
   }
   int cnt = 0 ;
   while(cnt <k-1){
    p.pop();
    cnt++;
   }
   int ans = p.top();
   return ans ;
}


int main(){
    int n   ;cin >> n ;
    int *arr = new int[n];
    for(int i = 0 ; i < n; i++){
        cin>>arr[i];
    }
    int k ; cin>> k ;
    int ans = kthlargest(arr , n , k);
    cout << ans << endl;
    delete []arr;
    return 0;
}