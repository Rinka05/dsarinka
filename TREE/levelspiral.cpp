
#include <bits/stdc++.h>
#include <iostream>
#include "input.cpp"
using namespace std;
class Node{
    public:
    int data ;
    Node* left;
    Node* right ;
    Node(int data){
        this->data = data ;
        left = NULL;
        right = NULL;
    }
};

// v , s s is temporary vector if insert NULL where we have to break
// at every level 
// if(temp == null)we insert Null at every step
// if level is odd we reverse s and then add it to v 
// resize s to 0
//
vector<int> findSpiral(Node *root)
{
    queue<Node*>q;
    vector<int>v, s;
    q.push(root);
    int level = 1;
    q.push(NULL);
    while(!q.empty()){
        Node* temp = q.front();
        q.pop();
       /* This code block is executed when a level in the binary tree has been completely traversed. */
        if(temp ==NULL){
            if(level%2!= 0){
                reverse(s.begin() , s.end());
            }
            for(auto i:s){
                v.push_back(i);
            }
            level++;
            s.resize(0);
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else {
            s.push_back(temp->data);
            if(temp->left)
            q.push(temp->left);
            if(temp->right){
                q.push(temp->right);
            }
        }
    }
    return v;
}















