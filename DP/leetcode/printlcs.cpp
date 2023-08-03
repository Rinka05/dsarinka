#include <bits/stdc++.h>
#include <iostream>
using namespace std;


void solve(string s , string t){
    int n = s.size();
    int m = t.size();
    vector<vector<int>>dp(n+1 , vector<int>(m+1 ,0));
    for(int i = 0 ; i<=n ; i++){
        dp[i][0] =0;
    }
    for(int  i = 0 ;  i<= m ; i++){
        dp[0][i] =0;
    }
    for(int i = 1 ; i <=n ; i++){
        for(int j = 1 ; j <= m ; j++){
            if(s[i-1]==t[j-1]){
                dp[i][j] =1+dp[i-1][j-1];
            }
            else{
                dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);
            }
        }
    }
 // find lcs length
    int len = dp[n][m];
    string ans="";
    for(int i = 0 ; i <len ; i++){
        ans+='$';
    }
    int index = len-1;
    int i = n , j = m;
    while(i>0 &&j >0){
        // match in the filled table if values are equal means we have to go to diagonal else two cases arive
        // from where we took element we have to go to that index i meant max of both so either i-- or j--

        if(s[i-1]==t[j-1]){
            ans[index]=s[i-1];
            index--;
            i--;j--;
        }
        else if(dp[i-1][j] >dp[i][j-1]){
            i--;
        }
        else{
            j--;
        }
    }
    cout << ans;
}



int main (){
    string s , t ; cin >> s >> t ;
    solve(s , t);
}