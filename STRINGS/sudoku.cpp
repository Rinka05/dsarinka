
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define n 9
bool emptylocation(int board[n][n],int &row,int &column){
   for(int i=0; i<n; i++){
      for(int j=0; j<n; j++){
         if(board[i][j]==0){
            row=i; 
            column=j;
            return true;
         }
      }
   }
   return false;
}
bool ispossible_in_row(int board[n][n],int row,int num){
    for(int i=0; i<n; i++){
       if(board[row][i]==num) return false;
    }
    return true;
}
bool ispossible_in_col(int board[n][n],int column,int num){
     for(int i=0; i<n; i++){
         if(board[i][column]==num){
             return false;
         }
     }
     return true;
}

bool ispossible_in_box(int board[n][n],int row, int column,int num){
     int rowfactor=row-(row%3);
     int columnfactor=column-(column%3);
     for(int i=0; i<3; i++){
         for(int j=0; j<3; j++){
            if(board[i+rowfactor][j+columnfactor]==num){
                return false;
            }
         }
     }
     return true;
}

bool ispossible(int board[n][n],int row,int column,int number){
     if(ispossible_in_row(board,row,number) and ispossible_in_col(board,column,number) and ispossible_in_box(board,row,column,number)){
        return true;
     }
     return false;
}
bool solvesuduko(int board[n][n]){
   int row,column;
   if( !emptylocation(board,row,column) ){
       return true;
   }
   for(int i=1; i<=9; i++){
      if(ispossible(board,row,column,i)){
         board[row][column]=i;
         if(solvesuduko(board)){
            return true;
         }
         board[row][column]=0;
      }
   }
   return false;
}

int main(){
// input  
    int board[n][n];
    for(int i=0; i<n; i++){
       string s; cin>>s;
       for(int j=0; j<s.length();j++){
          board[i][j]=s[j]-'0';
       }
    }
    solvesuduko(board);
    // print the suduko
    for(int i=0; i<n; i++){
       for(int j=0; j<n; j++){
           cout<<board[i][j];
       }
       cout<<endl;
    }
    return 0;
}











