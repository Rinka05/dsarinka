#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Node{
   public:
   int data ; 
   Node* left ;
   Node*right ;

   Node(int d){
    this->data = d ;
    this->left = NULL;
    this->right = NULL;
   }
};



Node* insertintobst(Node* &root , int d ){
    if(root==NULL){
        root = new Node(d);
        return root;
    }
    if(d > root->data)root->right = insertintobst(root->right , d);
    else root->left = insertintobst(root->left , d);
    return root;
}
void takeinput(Node* &root){
    int data ;
    cin >> data ;
    while(data != -1){
        insertintobst(root , data);
        cin >> data ;
    }
}

Node* minval(Node* root){
    Node* temp = root ;
    while(temp->left != NULL){
        temp = temp ->left;
    }
    return temp;
}
Node* maxval(Node* root){
    Node* temp = root;
    while(temp->right != NULL){
        temp = temp->right;
    }
    return temp;
}

Node* deletefrombst(Node* root , int val){
    // base case 
    if(root == NULL){
        return root;
    }
    if(root->data == val){
      //0 child
      if(root->left == NULL&& root->right ==NULL){delete(root) ;
      return NULL;}
      
      //1child
      if(root->left != NULL && root->right == NULL){
        Node* temp = root->left;
        delete root;
        return temp;
      }
      if(root->left == NULL && root->right != NULL){
        Node* temp = root->right;
        delete root;
        return temp;
      }
    //2child
    if(root->left != NULL && root->right != NULL){
        int mini = minval(root->right)->data;
        root->data = mini;
        root->right = deletefrombst(root->right , mini);
        delete root ;
        return root;
    }
    }
    
    else if (root->data >val){
        root->left = deletefrombst(root->left , val);
        return root ;
    }
    else {
        root->right = deletefrombst(root->right , val);
        return root;
    }
}

int main(){
     Node* root = NULL;
     takeinput(root);

}