#include <bits/stdc++.h>
#include <iostream>
using namespace std ;



int kanpsackdp(vector<int>wt , vector<int>val , int n , int maxweight){
    vector<vector<int>>dp(n , vector<int>(maxweight+1 , 0));
    for(int w = wt[0]; w<=maxweight ;w++){
        dp[0][w]= val[0];
    }
    for(int ind = 1 ; ind <n; ind++){
        for(int w = 0 ; w <= maxweight ; w++){
            int nottake = dp[ind-1][w];
            int take = INT_MIN;
            if(wt[ind]<=w){
                take = val[ind]+dp[ind-1][w-wt[ind]];
            }
            dp[ind][w] = max(take , nottake);
        }
    }
    return dp[n-1][maxweight+1];
}





int main(){








}
