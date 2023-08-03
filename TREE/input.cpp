#include <bits/stdc++.h>
#include <iostream>
using namespace std;
class Node{
    public:
   int data ;
   Node* left ;
   Node* right ;

   Node(int data ){
    this->data =data ;
    left = NULL;
    right = NULL;
   }
};



// function to build tree
Node* buildTree(string str){
    // corner case 
    if(str.length() ==0 || str[0]=='N'){
        return NULL;
    }
    // creating vector of string from input
    // string after splitting by space
    vector<string>ip;
    istringstream iss(str);
    for(string str ; iss>>str;)ip.push_back(str);

    Node* root = new Node(stoi(ip[0]));

    // push the root to the queue

    queue<Node*>queue;
    queue.push(root);
    int i = 1 ;
    while(!queue.empty() && i<ip.size()){
        Node* currNode = queue.front();
        queue.pop();
        string currVal = ip[i];

        // if left child is not null
        if(currVal != "N"){
              
              //create left child for current node 
              currNode ->left = new Node(stoi(currVal));
              queue.push(currNode->left);
        }
        i++;
        if(i >= ip.size()){
            break;
        }
        currVal = ip[i];
        /// if right child is not null
        if(currVal != "N"){
            currNode->right = new Node(stoi(currVal));
            queue.push(currNode->right);
        }
        i++;
    }
    return root;
}
