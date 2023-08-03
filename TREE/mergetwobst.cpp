


// The way if it's all predetermined
//  *         And the way i should go all my life
//  *             I swear to go wherever will be
//  *                 'Cause there'll be something to see and to find



#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define MAX_HEIGHT 100000

struct Node{
    int data ;
    Node* left ;
    Node* right ;
    Node(int val){
        data = val ;
        left = right = NULL;
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


class Solution
{
    public:
  void inorder(Node* temp , vector<int> &v){
      if(temp == NULL)return ;
      inorder(temp->left , v);
      v.push_back(temp->data);
      inorder(temp->right , v);
  }
  vector<int>mergeboth(vector<int> &bst1 , vector<int>&bst2){
      vector<int>ans(bst1.size()+bst2.size());
      int i = 0 , j = 0 ,k=0;
      while(i < bst1.size() && j < bst2.size()){
          if(bst1[i]<bst2[j]){
              ans[k++] = bst1[i++];
          }
          else {
              ans[k++] = bst2[j++];
          }
      }
      while(i < bst1.size()){
          ans[k++] = bst1[i++];
      }
      while(j < bst2.size()){
          ans[k++] = bst2[j++];
      }
  }
  Node* inordertobst(int s , int e , vector<int> &inorder){
      if(s > e)return NULL;
      int mid = (s+e)/2;
      
      Node* root = new Node(inorder[mid]);
      root->left = inordertobst(s , mid-1 , inorder);
      root->right = inordertobst(mid+1 , e , inorder);
      return root;
  }
    vector<int> merge(Node *root1, Node *root2)
    {
      vector<int> bst1 , bst2;
      inorder(root1 , bst1);
      inorder(root2 , bst2);
     vector<int>merged =   mergeboth(bst1 , bst2);
    //  int s = 0 , e = merged.size()-1 ;
    //  return inordertobst(s , e , merged);
     return merged;
    }
};

int main(){
    int t ; string tc;
    getline(cin , tc);
    t = stoi(tc);
    while(t--){
        string s ; getline(cin ,s );
        Node* root1 = buildTree(s);

        getline(cin , s);
        Node* root2 = buildTree(s);

        Solution obj;
        vector<int> vec = obj.merge(root1 , root2);
        for(int i = 0 ; i < vec.size(); i++)
            cout << vec[i] << " ";
            cout << endl;
       
    }
     return 0;
}
