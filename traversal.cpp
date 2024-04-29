#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node* next;
};

int main(){
  struct Node* head;
  head = (struct Node *) malloc(sizeof(struct Node));
  Node* second = (struct Node *) malloc(sizeof(struct Node));
  Node* third = (struct Node *) malloc(sizeof(struct Node));
   head->data= 7;
   head->next = second;
   second->data = 11;
   second->next = third;
   third->data = 13;
   third->next = NULL;
   while(head != NULL){
    cout << head->next<< endl;
    head = head->next;
   }
    
}