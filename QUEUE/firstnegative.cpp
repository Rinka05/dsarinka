#include <bits/stdc++.h>
#include <iostream>
using namespace std;
//in  window size k first negative number 
vector<long long>printfirstnegative(long long int a[], long long int n , long long int k){
  deque<long long int>dq;
  vector<long long >ans;
  // first window process
  for(int i = 0 ; i < k ;i++){
    if(a[i]<0){
        dq.push_back(i);
    }
  }
  if(dq.size()>0){
    ans.push_back(a[dq.front()]);
  }
  else{
    ans.push_back(0);
  }

  for(int i = k ; i < n ; i++){
    if(!dq.empty()&&i-dq.front()>=k){
        dq.pop_front();
    }
    // addition
        if(a[i]<0){
            dq.push_back(i);
        }

    //ans store
    if(dq.size()>0){
        ans.push_back(a[dq.front()]);
    }
    else{
        ans.push_back(0);
    }
    
  }
return ans;
}



// optimal


int main(){
    
}



    


