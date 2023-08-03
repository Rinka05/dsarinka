#include <bits/stdc++.h>
#include <iostream>
using namespace std;


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
// */

vector<int>getpathbfs(int **edges ,int n , int v1 , int v2){
    bool *visited = new bool[n];
    for(int i = 0 ; i < n ; i++){
        visited[i]= false;
    }
    queue<int>q;
    q.push(v1);
    visited[v1] = true ;
    unordered_map<int, int>mp;
    while(!q.empty()){
        int front = q.front();
        if(front ==v2){
            break;
        }
        q.pop();
        for(int i = 0 ; i < n; i++){
            if(edges[front][i] ==1 && !visited[i]){
                q.push(i);
                visited[i] = true ;
                mp[i]= front;
            }
        }
    }
   /* This code snippet is part of a function called `getpathbfs` which is used to find the shortest
   path between two vertices in a graph using Breadth-First Search (BFS) algorithm. */
    if(q.empty()){
        vector<int>ans(0);
        return ans ;
    }
 
    else{
        vector<int>output;
        output.push_back(v2);
        while(v2 != v1){
            output.push_back(mp[v2]);
            v2 = mp[v2];
        }
       
        return output;
    }


    delete []visited;

}

















int main(){
    int n , e ; cin >> n >>e ;
    int **edges = new int*[n];
    for(int i = 0 ; i < n ; i++){
        edges[i]= new int[n];
    for(int j= 0 ; j < n ; j++){
        edges[i][j]=0;
    }
    }
    for(int i = 0 ; i < e ; i++){
        int f , s ; cin >> f >>s ; 
        edges[f][s] = 1;
        edges[s][f] =1;
    }
    int v1 , v2 ; cin >>v1>>v2;
    vector<int> ans = getpathbfs(edges , n , v1 , v2);
    for(int i = 0 ; i < ans.size() ;i++){
        cout <<ans[i]<<" ";
    }

}