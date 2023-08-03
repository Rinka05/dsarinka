#include <bits/stdc++.h>
#include <iostream>
using namespace std;

void printpaths(int** input , int n , int**visited , int x , int y){
     if(x==n-1 && y==n-1){
        visited[x][y]=1;
        for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            cout << visited[i][j] << " ";
        }
        cout << endl;
        }
        cout << endl;
        return ;
    }
    if(x<0 ||y<0 ||x>= n ||y>=n||input[x][y]==0 ||visited[x][y]==1){
        return;
    }
    visited[x][y]=1;
    printpaths(input , n , visited , x-1 , y);
    printpaths(input , n  , visited , x+1 , y);
    printpaths(input , n , visited , x , y+1);
    printpaths(input , n , visited , x ,y-1);

}






 bool haspathhelper(int**input , int n , int **visited , int x , int y ){
    if(x==n-1 && y==n-1){
        return true ;
    }
    if(x<0 ||y<0 ||x>= n ||y>=n||input[x][y]==0 ||visited[x][y]==1){
        return false ;
    }
    visited[x][y]=1;
    if(haspathhelper(input , n , visited , x-1 , y)){
        return true ;
    }
    if(haspathhelper(input , n , visited , x+1 , y)){
        return true ;
    }
    if(haspathhelper(input , n , visited , x, y-1)){
        return true ;
    }
    if(haspathhelper(input , n , visited , x , y+1)){
        return true ;
    }
    visited[x][y] = 0;
    return false ;

 }



bool haspath(int**arr , int n){
  int ** visited = new int*[n];
  for(int i = 0 ; i < n ; i++){
    visited[i] = new int[n];
    for(int j = 0  ; j < n ; j++){
        visited[i][j]=0;
    }
  }
  printpaths(arr , n , visited ,0,0 );
//   return haspathhelper(arr  , n , visited, 0,0 );
}






int main(){
  int **arr ;
  int n ; cin>> n ;
  arr = new int*[n];
  for(int i = 0 ; i < n ; i++){
    arr[i] = new int[n];
  for(int j = 0 ; j < n ; j++){
    cin >> arr[i][j];
  }
  }
 cout << haspath(arr , n)<< endl;
}








