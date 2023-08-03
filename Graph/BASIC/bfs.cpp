

#include <bits/stdc++.h>
#include <iostream>
using namespace std ;


void printbfs(int **edges , int n , int s , bool *visited){
    queue<int>q ;
    q.push(s);
    visited[s]= true ;
    while(!q.empty()){
        int front = q.front();
        q.pop();
        cout <<front << " ";
        for(int i = 0 ; i < n ; i++){
            if(i == front )continue;
            if(edges[s][i] == 1 && !visited[i]){
                q.push(i);
                visited[i] = true;
            }
        }
    }
}

void bfs(int **edges , int n ){
    bool *visited = new bool[n];
    for(int i = 0 ; i < n  ;i++){
        visited[i]= false ;
    }
    for(int i = 0 ; i < n ; i++){
        if(!visited[i]){
            printbfs(edges , n ,i, visited );
        }
    }
    delete []visited;
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
   bfs(edges , n);

    for(int i = 0 ; i < n ; i++){
        delete []edges[i];
    }
    delete []edges;
}