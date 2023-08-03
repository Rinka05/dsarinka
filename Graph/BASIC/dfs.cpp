#include <bits/stdc++.h>
#include <iostream>
using namespace std;

void printdfs(int **edges , int n , int s , bool *visited){
    cout << s << " ";
    visited[s]= true ;
    for(int i = 0 ; i < n ; i++){
     if(i==s)continue;
     if(edges[s][i] ==1&& !visited[i]){
         printdfs(edges , n , i , visited);
     }
    }
}

void dfs(int ** edges , int n){
    bool *visited = new bool[n];
    for(int i = 0 ; i < n ; i++){
        visited[i] = false;
    }
    for(int i = 0 ; i < n ; i ++){
        if(!visited[i]){
            printdfs(edges , n , i , visited);
        }
    }
}

int main(){
    int n ,  e ; cin >> n >> e ;

    // matrix
    int **edges = new int *[n];
    for(int i = 0 ; i < n ; i++){
        edges[i]= new int[n];
    for(int j = 0; j < n ; j++){
        edges[i][j] = 0;
    }
    }
    // take all input for edges between nodes
    for(int i = 0 ; i < e ; i++){
        int f , s ; cin >> f >> s ;
        edges[f][s] = 1 ;
        edges[s][f] = 1;
    }
    cout <<"dfs is " << endl;
     dfs(edges , n) ;

}