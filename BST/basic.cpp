#include <iostream>
#include <bits/stdc++.h>
using namespace std ;

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
void levelorder(Node*root ){
    queue<Node*>q;
    q.push(root);
    q.push(NULL);
    // endl dene ke liye 

    while(!q.empty()){
        Node*temp = q.front();
        q.pop();
        if(temp == NULL){
            cout << endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else {
            cout << temp->data << " ";
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
    }
}

// inorder of bst is sorted
void inorder(Node* root){
    if(root==NULL)return ;
     inorder(root->left);
     cout << root->data<<" ";
     inorder(root->right);
}

Node* insertintobst(Node* &root , int d ){
    if(root==NULL){
        root = new Node(d);
        return root;
    }
    if(d > root->data){
        root->right = insertintobst(root->right , d);
    }
    else{
        root->left = insertintobst(root->left , d);
            }
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


int main(){

 Node* root = NULL;
 takeinput(root);
 levelorder(root);
 cout << endl;
 inorder(root);

}