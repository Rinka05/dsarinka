#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int memo[1001][1001];
int dp[1001][1001];
int recursion(string s , string p){
    int n = s.length() ; int m = p.length();
    if(n==0 || m==0){
        return 0;
    }
    if(s[0]== p[0]){
        return 1+recursion(s.substr(1), p.substr(1));
    }
    else {
        return max(recursion(s , p.substr(1)) , recursion(s.substr(1) , p));
    }
}


int memoise(string s , string p){
 int n = s.length(), m = p.length();
 if(n==0|| m==0)return 0;
 if(memo[n][m]!= -1){
    return memo[n][m];
 }
 
 if(s[0]==p[0]){
   memo[n][m] = 1+memoise(s.substr(1),p.substr(1));
 }
 else{
       memo[n][m] = max(memoise(s.substr(1),p) , memoise(s,p.substr(1)));
 }
 return memo[n][m];
 
}

// dp galat hai 


int dplcs(string s , string p){
    int n= s.length(), m= p.length();
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            if(i==0 || j==0){
                dp[i][j] = 0;
            }
        }
    }
    for(int i = 1 ; i < n ; i++){
        for(int j = 1 ; j < m ; j++){
            if(s[i-1]== s[j-1]){
                dp[i][j] = 1+dp[i-1][j-1];
            }
            else {
                dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);
            }
        }
    }
    
return dp[n-1][m-1];
}






int main(){
    string x ;string y ;
    cin >> x >> y ;
    memset(memo , -1 , sizeof(memo));
    cout << recursion(x , y) << endl;
   cout <<  memoise(x ,y)<<endl;

}





