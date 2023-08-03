#include <bits/stdc++.h>
#include <iostream>
using namespace std ;

// Sample Input 1 :
// 4 4
// 0 1
// 0 3
// 1 2
// 2 3
// 1 3
// Sample Output 1 :
// 3 0 1
// Sample Input 2 :
// 6 3
// 5 3
// 0 1
// 3 4
// 0 3
// Sample Output 2 :
//


vector<int>*getpathhelper(int **edges , int n , int s , int e , bool *visited){
    if(s==e){
        vector<int>*ans = new vector<int>();
        ans->push_back(e);
        return ans ;
    }
    visited[s] = true ;
    for(int i=0; i <n ; i++) {
        if(edges[s][i]==1 && !visited[i]){
           vector<int>* smalloutput = getpathhelper(edges , n , i , e , visited);
           if(smalloutput!= NULL){
            smalloutput->push_back(s);
            return smalloutput;
           }
        }
    }
  return NULL;
}


vector<int>*getpath(int **edges , int n , int s , int e){
    bool *visited = new bool[n];
    for(int i = 0 ; i < n ; i++){
        visited[i] = false;
    }
    vector<int>*output = getpathhelper(edges , n , s , e , visited);
    delete []visited;
    return output;
    
}
int main(){
    int n , e ; cin >> n >> e ;
    int **edges = new int*[n];
    for(int i = 0 ; i < n ; i++){
        edges[i] = new int[n];
    for(int j = 0 ; j < n ; j++){
        edges[i][j]=0;
    }
    }
    // take edge input 
    for(int  i = 0 ; i < e ; i++){
        int f , s ; cin >> f >>s ;
        edges[f][s] = 1;
        edges[s][f] =1;
    }
    // path between two vertices
    int v1 , v2 ; cin>> v1 >>v2;
    vector<int>*ans = getpath(edges , n , v1 , v2);
    if(ans != NULL){
        for(int i = 0 ; i <ans->size();i++){
            cout <<ans->at(i)<< " ";
        }
    }

}