#include <bits/stdc++.h>
using namespace std;

template <typename T>

class BinaryTreeNode{
  public:
  T data ;
  BinaryTreeNode *left;
  BinaryTreeNode *right;

  BinaryTreeNode(T data){
      this->data = data;
      this->left = NULL;
      this->right = NULL;
  }
  ~BinaryTreeNode(){
    delete left;
    delete right;
  }

};

int maximum(BinaryTreeNode<int>*root){
  if(root == NULL){
    return INT_MIN;
  }
  return max(root->data , max(maximum(root->left) , maximum(root->right)));
}
int minimum(BinaryTreeNode<int>*root){
    if(root==NULL){
        return INT_MAX;
    }
    return min(root->data , min(minimum(root->left) , minimum(root->right)));

}
bool isBst(BinaryTreeNode<int>*root){
    if(root == NULL)return true ;
    int leftmax = maximum(root->left);
    int rightmin = minimum(root->right);
    bool output = (root->data >leftmax)&& (root->data <= rightmin)&&isBst(root->left)&&isBst(root->right);
    return output;
}


class isBstReturn{
    public:
    bool isBst ;
    int minimum ;
    int maximum;

};
isBstReturn isBst2(BinaryTreeNode<int>*root){
    if(root== NULL){
        isBstReturn output;
        output.isBst = true;
        output.minimum = INT_MAX;
        output.maximum = INT_MIN;
        return output;
    }
    isBstReturn leftoutput = isBst2(root->left);
    isBstReturn rightoutput = isBst2(root->right);
    int minimum = min(root->data , min(leftoutput.minimum , rightoutput.minimum));
    int maximum = max(root->data , max(leftoutput.maximum , rightoutput.maximum));
    bool isfinalbst = (root->data >leftoutput.maximum )&&(root->data <= rightoutput.minimum)&& leftoutput.isBst&& rightoutput.isBst;
    isBstReturn output ;
    output.minimum = minimum;
    output.maximum = maximum;
    output.isBst = isfinalbst;
    return output;
}
