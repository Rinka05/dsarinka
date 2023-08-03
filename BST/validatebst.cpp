#include <bits/stdc++.h>
using namespace std ;


class Node{
  public:
  int data ; 
  Node* left ;
  Node* right;
  Node(int d){
    this->data = d ;
    this->left = NULL;
    this->right = NULL;
  }
};


bool isbst(Node* root , int min , int max){
    if(root == NULL)return true ;
    // checking in the range
    if(root ->data >= min && root->data <= max){
        bool left = isbst(root->left , min , root->data);
        bool right = isbst(root->right , root->data , max);
        return left &right;
    }
     else return false ;
}


int main(){

 
}