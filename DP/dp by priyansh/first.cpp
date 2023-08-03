#include <bits/stdc++.h>
#include <iostream>
using namespace std;
const int  n = 1e5+1;
//state 
// transition
// base case 
// final subproblem
int dp[n+1];
int numberofways(int n ){
    if(n<0)return 0;
    if(n==0)return 1;
    if(dp[n]!=-1){
        return dp[n];
    }
    dp[n]=0;
    for(int i = 1 ; i <= 6 ; i++){
        dp[n] +=numberofways(n-i);
    }
    return dp[n];
}

void solve(){
    cout << numberofways(n) << endl;
}
int main(){

}