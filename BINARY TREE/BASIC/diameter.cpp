#include <iostream>
#include "basic.cpp"
#include <queue>
#include <vector>

using namespace std;




int height(BinaryTreeNode<int>*root){
    if(root==NULL){
        return 0;

    }
    return 1+max(height(root->right) , height(root->left));
}

int diameter(BinaryTreeNode<int>* root ){
    if(root == NULL){
        return 0;
    }
    int option1 = height(root->right)+height(root->left);
    int option2 = diameter(root->right);
    int option3 = diameter(root->left);
    return max(option1 , max(option2, option3));
}

pair<int,int>heightdiameter(BinaryTreeNode<int>*root){
    if(root == NULL){
        pair<int,int>p;
        p.first = 0;
        p.second = 0;
        return p;
    }
    pair<int,int> leftans = heightdiameter(root->left);
    pair<int, int>rightans = heightdiameter(root->right);
    int ld = leftans.second;
    int lh = leftans.first;
    int rd= rightans.second;
    int rh = rightans.first;
     int height = 1+max(lh , rh);
     int diameter = max(lh+rh , max(ld , rd));
     pair<int, int>p;
     p.first = height ;
     p.second = diameter;
     return p;

}


int main(){
    
}