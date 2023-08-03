#include <bits/stdc++.h>
#include <iostream>
using namespace std ;

bool fr(int ind , int target , vector<int>&arr){
    if(target ==0)return true ;
    if(ind ==0)return (arr[0]==target);
    bool nottake = fr(ind-1 , target , arr);
    bool take = false ;
    if(arr[ind]<target)take = fr(ind-1 , target-arr[ind],arr);
    return take||nottake;
}

bool fmemo(int ind , int target , vector<int>&arr , vector<vector<int>>&dp){
    if(target ==0){
        return true ;
    }
    if(ind ==0)return (arr[0]==target);
    if(dp[ind][target]!=-1)return dp[ind][target];
    bool nottake = fmemo(ind-1 , target , arr ,dp);
    bool take =false ;
    if(arr[ind]<=target)take = fmemo(ind-1 , target-arr[ind], arr ,dp);
    return dp[ind][target] = take||nottake;

}


bool subsetsumk(int n , int k , vector<int>&arr){
   return fr(n-1 , k , arr);
}

bool subsetsummemo(int n , int k , vector<int>&arr){
    vector<vector<int>> dp(n , vector<int>(k+1 , -1));
    return fmemo(n-1 , k , arr ,dp);
}

bool subsetsumkdp(int n , int k , vector<int>&arr){
    vector<vector<int>>dp(n , vector<int>(k+1 , 0));
    for(int i = 0 ; i < n ; i++){
        dp[i][0] = true ;
    }
    dp[0][arr[0]] = true;
    for(int ind =1 ; ind <n ; ind++){
        for(int target = 1 ;target <k ; target++){
            bool nottake = dp[ind-1][target];
            bool take = false ;
            if(arr[ind]<= target){
                take = dp[ind-1][target-arr[ind]];
            }
            dp[ind][target] = take||nottake;
        }
    }
    return dp[n-1][k];
}

int main(){

}