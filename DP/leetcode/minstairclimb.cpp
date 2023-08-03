
#include <bits/stc++.h>
#include <iostream>
using namespace std;


class Solution {
public:
int solve(int index , vector<int>&cost , int n , vector<int>&dp){
    if(index >=n)return 0;
    if(dp[index]!=-1)return dp[index];
    int onestep = solve(index+1 , cost , n , dp)+cost[index];
    int twostep = solve(index+2 , cost , n , dp)+cost[index];
    return dp[index]= min(onestep , twostep);
}
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
    //     vector<int>dp(n+1 , -1);
    //   int ans1=  solve(0 , cost , n , dp);
    //   int ans2 = solve(1 , cost , n , dp);
    //  return min(ans1 , ans2);


    // vector<int>dp(n+1);
    // dp[0]= cost[0];
    // dp[1]= cost[1];
    // for(int i = 2 ; i <= n ; i++){
    //     if(i <n )dp[i]= cost[i]+min(dp[i-1] , dp[i-2]);
    //     else dp[i] = 0+min(dp[i-1] , dp[i-2]);
    // }
    // return dp[n];


  // space optimized
  int prev2 = cost[0];
  int prev1 = cost[1];
  for(int i = 2 ; i <= n ; i++){
      int current = (i<n? cost[i]:0)+min(prev1 , prev2);
      prev2 = prev1;
      prev1 = current;
  }
  return prev1;
    }
};