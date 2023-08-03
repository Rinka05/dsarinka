#include <bits/stdc++.h>
#include <iostream>
using namespace std;


class Solution {
public:
int minFallingpath(vector<vector<int>>&matrix , int r , int c , vector<vector<int>>&dp){
    if(r==0 and c<matrix[0].size() and c>=0)return matrix[r][c];
    if(c>=matrix[0].size() or c<0)return INT_MAX;
    if(dp[r][c] != -1)return dp[r][c];
    return matrix[r][c]+min(min(minFallingpath(matrix , r-1 ,c+1,dp), minFallingpath(matrix , r-1 , c,dp )) , minFallingpath(matrix , r-1 , c-1,dp));
}
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int rows = matrix.size(), cols = matrix[0].size();
        int ans = INT_MAX;
        vector<vector<int>>dp(rows+1 , vector<int>(cols+1 , INT_MAX));
        for(int c = 0 ; c <cols ; c++){
            ans = min(ans , minFallingpath(matrix , rows-1 , c ,dp));
        }
        return ans ;
    }
};