#include <iostream>
#include <queue>
#include "basic.cpp"
using namespace std;

void printbinarytree(BinaryTreeNode<int> *root){
    if (root== NULL){
        return ;
    }
   cout << root->data<< endl;
   if(root->left != NULL){
    cout << "L" << root->left->data;
   }
   if(root->right != NULL){
    cout << "R" << root->right->data ;
   }
   cout << endl;
   printbinarytree(root->left);
   printbinarytree(root->right);


}
BinaryTreeNode<int>*takeinput(){
    int rootdata ;
    cout << "enter data "<< endl;
    cin >>rootdata ;
    if(rootdata == -1){
        return NULL;
    }
    BinaryTreeNode<int>*root = new BinaryTreeNode<int>(rootdata);
    BinaryTreeNode<int>* leftchild = takeinput();
    BinaryTreeNode<int>* rightchild = takeinput();
    root->left = leftchild;
    root->right = rightchild;
    return root;

}
BinaryTreeNode<int>*takeinputlevelwise(){
    int rootdata;
    cout << "enter data"<< endl;
    cin >> rootdata;
    if(rootdata==-1){
        return NULL;
    }
    BinaryTreeNode<int>*root = new BinaryTreeNode<int>(rootdata);
    queue<BinaryTreeNode<int>*>Nodes;
    Nodes.push(root);
    while(Nodes.size()!= 0){
      BinaryTreeNode<int>*front = Nodes.front();
      Nodes.pop();
      cout << "enter left child of "<< front->data << endl;
      int leftchilddata ;
      if(leftchilddata != -1){
        BinaryTreeNode<int>*child = new BinaryTreeNode<int>(leftchilddata);
        front->left = child;
        Nodes.push(child);
      }
      cout << "enter right data "<< front ->data << endl;
      int rightchilddata ;
      cin >> rightchilddata ;
      if(rightchilddata!= -1){
        BinaryTreeNode<int>*child = new BinaryTreeNode<int>(rightchilddata);
        front->right = child ;
        Nodes.push(child);
      }
    }
    return root;
}




int main(){  
//   BinaryTreeNode<int>* root = new BinaryTreeNode<int>(1);
//   BinaryTreeNode<int>*node1 = new BinaryTreeNode<int>(2);
//   BinaryTreeNode<int>*node2 = new BinaryTreeNode<int>(3);
//   root->left = node1;
//   root->right = node2;
// BinaryTreeNode<int>*root =takeinput();
BinaryTreeNode<int>*root =takeinputlevelwise();
  printbinarytree(root);
  delete root;


}

