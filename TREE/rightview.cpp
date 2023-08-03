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
class solution{
    public:
    vector<int>rightview(Node* root){
        vector<int>ans;
        queue<Node*>q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            for(int i = 0 ; i < size ; i++){
                Node* front = q.front();
                q.pop();
                if(i == 0){
                    ans.push_back(front->data);
                }
                if(front->right){
                    q.push(front->right);
                }
                if(front->left){
                    q.push(front->left);
                }
            }
        }
         return ans;
    }
   
};




int main(){


return 0;
}