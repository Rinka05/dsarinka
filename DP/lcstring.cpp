#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int lcs(string s , string p ,int dp[n][m]){
 int n = s.length(); int m = p.length();
    for(int i = 0 ; i < n ; i ++){
        for(int j = 0 ; j < m ; j++){
            if(i==0|| j ==0 )  {
                dp[i][j]=0;
            }    
          } 
    }
for(int i = 1 ; i < n ; i ++){
        for(int j = 1 ; j < m ; j++){
            if(s[i-1]== s[j-1]){
                dp[i][j] = 1+dp[i-1][j-1];
            }
            else {
                dp[i][j]=0;
            } 
          } 
    }
return dp[n][m];


}



int main(){
    string s , p ; cin >> s >> p;
    int n = s.length(); int m = p.length();
    int dp[n+1][m+1];
    cout << lcs(s , p , dp);
    
}