#include <bits/stdc++.h>
#include <iostream>
using namespace std;





class Solution {
public:
int solve(int i , int j , int n , vector<vector<int>>&triangle , vector<vector<int>>&dp){
    if(i==n)return 0;
    if(dp[i][j]!=-1)return dp[i][j];
    int left = triangle[i][j]+solve(i+1 , j , n , triangle , dp);
    int right = triangle[i][j]+solve(i+1 , j+1 , n , triangle , dp);
    dp[i][j] = min(left , right);
    return dp[i][j];
}
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>>dp(n , vector<int>(n , -1));
        return solve(0  , 0 , n , triangle , dp);
    }
};






