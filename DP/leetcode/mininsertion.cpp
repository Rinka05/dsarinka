// minimum number of insertions to make a string palindrome 
//stringlength-lcs(string s , reverse of string s)

// this code gives longest common palindromic subsequence




// min insertions and deletions to convert one string to other 
// sum of lenghts of two strings and substract two times of lcs of both the strings

#include <bits/stdc++.h>
#include <iostream>
using namespace std;


void lcs(string s1 , string s2){
    int n = s1.length();
    int m = s2.length();
    vector<vector<int>>dp(n+1 , vector<int>(m+1 ,0));
    for(int i = 0 ; i <= n  ; i++)dp[i][0]=0;
    for(int j = 0 ; j <= m ; j++)dp[0][j]=0;
    for(int i = 1 ; i <= n  ; i++){
        for(int j = 1 ; j <= m ; j++){
            if(s1[i-1]==s2[j-1]){
                 dp[i][j] = 1+dp[i-1][j-1];
            }
            else{
               dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);
            }
        }
    }
  int len = dp[n][m];
  int i = n  , j= m , index = len-1;
  string ans = "";
  for(int i = 0 ; i  < len ; i++){
    ans+='$';
  }
  while( i >0 && j >0){
    if(s1[i-1]==s2[j-1]){
          ans[index]= s1[i-1];
          i--;
          j--;
          index--;
    }
    else if(dp[i-1][j]>dp[i][j-1]){
        i--;
    }
    else{
        j--;
    }
  }
  cout << ans<< endl;
}

int main(){
    string s  ;
    cin >> s;
    string t = s ;
    reverse(s.rbegin(), s.rend());
   
   lcs(s , t);


}