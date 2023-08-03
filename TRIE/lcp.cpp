#include <bits/stdc++.h>
#include <iostream>
using namespace std;
class TrieNode{
    public:
   char data ;
   TrieNode* children[26];
   bool isterminal;
   TrieNode(char ch){
    data = ch;
   for(int i = 0 ; i < 26 ; i++){
    children[i] = NULL;
   }
   isterminal = false ;
   }
};

class Trie{
   public:
    TrieNode*  root;
   Trie(char ch){
    root = new TrieNode('\0');
   }
  




};


int main(){


    return 0;
}