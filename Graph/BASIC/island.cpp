#include <bits/stdc++.h>
#include <iostream>
using namespace std;


int main(){
    int n , e ; 
    cin >> n >> e;
    int **edges = new int*[n];
    for(int i = 0 ; i < n ; i++){
        edges[i] = new int[n];
    for(int j = 0 ; j < n ; j++){
      edges[i][j] = 0;
    }
    }
    for(int i = 0 ; i < e ; i++){
        int f , s ; cin >> f >> s;
        edges[f][s]=1;
        edges[s][f]=1;
    }
    bool *visited = new bool[n];
    for(int i = 0 ; i < n ; i++){
        visited[i] = false ;
    }
    
}