

#include <bits/stdc++.h>
#include <iostream>
using namespace std;


struct Node{
    int data ;
    Node* left ;
    Node* right ;
    Node(int val ){
        data = val ;
        left = right = NULL;
    }
};






class Solution{
    public:
        Node* LCA(Node *root, int n1, int n2)
        {
            if(root == NULL){
                return root;
            }
            int val = root->data ;
            if(val <n1 && val <n2){
                return LCA(root->right , n1 , n2);
            }
            if(val >n1 && val >n2){
                return LCA(root->left , n1 , n2);
            }
            return root;
        }

};