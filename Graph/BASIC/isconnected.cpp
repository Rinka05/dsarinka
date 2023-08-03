#include <iostream>
#include <bits/stdc++.h>
using namespace std;


bool isconnected(int **edges , int n ,int s ,bool *visited ){
    visited[s] = true ;
    for(int i = 0 ; i < n ; i++){
        if(edges[s][i] ==1 && !visited[i]){
           isconnected(edges , n , i , visited);
        }
    }

    for(int i = 0 ; i < n ; i++){
        if(visited[i] == false){
            return false ;
        }
    }
    return true ;
}


int main(){
    int n , e ; cin>> n >> e ;
    int **edges = new int*[n];
    for(int i= 0 ; i < n ; i++){
        edges[i] = new int[n];
    for(int j = 0 ; j < n ; j++){
        edges[i][j]=0;
    }
    }
   bool *visited = new bool[n];
   for(int i = 0 ; i < n ; i++){
    visited[i] = false ;
   }
    // take edge input 
    for(int i =0 ; i <e ; i++){
        int f , s ; cin>> f >>s ;
        edges[f][s] =1;
        edges[s][f] =1;
    }
    if(isconnected(edges , n ,0, visited)){
        cout << "yes the componenets are connected"<<endl;
    }
    else {
        cout <<"no the components are not connected" << endl;
    }
}