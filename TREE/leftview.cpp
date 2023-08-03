#include <bits/stdc++.h>
#include <iostream>

using namespace std;

struct Node{
    int data ;
    struct Node* left ;
    struct Node* right ;
    Node(int x){
        data = x;
        left = right = NULL;
    }
};

vector<int> leftView(Node *root)
{  
   vector<int>ans;
   if(root == NULL)return ans ;
   queue <Node*>q;
   q.push(root);
   while(!q.empty()){
       int size = q.size();
       for(int i = 0 ; i < size ; i++){
           Node* curr = q.front();
           q.pop();
           if(i ==0)ans.push_back(curr->data);
           if(curr->left)q.push(curr->left);
           if(curr->right)q.push(curr->right);
       }
   }
   return ans;
}




