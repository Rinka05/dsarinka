#include <bits/stdc++.h>
using namespace std ;

int f(int ind , int t , vector<int>&nums){
    if(ind ==0){
        if(t%nums[0]==0)return t/nums[0];
        return 1e9;
    }

    int nottake = 0+f(ind-1 , t , nums);
    int take = INT_MAX;
    if(nums[ind]<=t)take = 1+f(ind,t-nums[ind],nums);
    return max(take , nottake);
}
int fmemo(int ind, int target , vector<int>&num , vector<vector<int>>&dp){
    if(ind ==0){
        if(target%num[0]==0)return target/num[0];
        return 1e9;
    }
    if(dp[ind][target]!=-1)return dp[ind][target];
    int nottake = fmemo(ind-1 , target , num, dp);
    int take = INT_MAX;
    if(num[ind]<=target){
        take = 1+fmemo(ind , target-num[ind] , num , dp);
    }
    return dp[ind][target]= max(take , nottake);
}

int fm(vector<int>&nums , int target){
    int n = nums.size();
    vector<vector<int>>dp(n , vector<int>(target+1 , -1));
    int ans = fmemo(n-1 , target , nums ,dp);
    if(ans >=1e9)return -1;
    return ans ;
}


int main(){
   
}