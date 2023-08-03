#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class TrieNode{
    public:
    char data ;
    TrieNode* children[26];
    bool isterminal;
    TrieNode(char ch){
      data = ch;
      for(int i = 0 ; i < 26 ; i++){
        children[i]=NULL;
      }
      isterminal = false ;
    }
};
class Trie{
 public:
 TrieNode* root ;
// constructor
Trie(){
    root = new TrieNode('\0');
}
 void insertutil(TrieNode* root , string word){
    // base case
          if(word.length()==0){
            root->isterminal = true;
            return;
          }
          //word is caps
          int index = word[0]-'A';
          TrieNode* child;

          //present
          if(root->children[index]!= NULL){
            child = root->children[index];
          }
          else {
            //absent
            child = new TrieNode(word[0]);
            root->children[index] = child;
          }
          //recursion
          insertutil(child , word.substr(1));
 }

 void insertword(string word){
    insertutil(root , word);
 }
 bool searchutil(TrieNode* root , string word){
  if(word.length()==0){
    return root->isterminal;
  }
  int index = word[0]-'A';
  TrieNode* child;
  if(root-> children[index] != NULL){
    child = root->children[index];
  }
  else{
    // absent
    return false;
  }
  return searchutil(child , word.substr(1));
 }

 bool search(string word){
   return searchutil(root , word);
 }
};


int main(){
   Trie* t = new Trie();
   t->insertword("ABCD");
   t->insertword("TIME");
   cout << "present or not  "<< t->search("ABCD") << endl;
   cout << "iamrinka    " << t->search("TIME")<< endl;
    return 0;
}

