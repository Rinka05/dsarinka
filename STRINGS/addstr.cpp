#include <bits/stdc++.h>
#include<iostream>
using namespace std ;

class Solution {
  public:
    string findSum(string x, string y) {
        string ans = "";
        int carry = 0;
        int i =x.length()-1;
        int j = y.length()-1;
        while(i >= 0|| j >=0 || carry){
            int a = 0,  b =0;
            if(i >=0 ) a=x[i--]-'0';
            if(j >=0 ) b = y[j--]-'0';
            int digit = a+b+carry ;
            carry = digit/10;
            ans.push_back((digit%10)+'0');
        }
        reverse(ans.begin(), ans.end());
        while(ans.length()>1 && ans[0]=='0'){
            ans.erase(0,1);
            
        }
        return ans ;
    }
};

int main (){
    int t  ; cin >> t ;
    while(t--){
        string x , y ;
        cin >> x>>y ;
        Solution o;
        cout << o.findSum(x , y)<< endl;

    }
}


