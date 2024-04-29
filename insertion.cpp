#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node* next;
};

struct Node* insertathead(struct Node* head , int data){
    struct Node* ptr  = (struct Node*) malloc(sizeof(struct Node));
    ptr->next = head;
    ptr->data = data;
}
struct Node* insertatindex(struct Node* head , int data , int index){
    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
    struct Node* p = head;
    int i = 0 ; 
    while(i != index-1){
        p = p->next;
        i++;
    }
    ptr->data = data ;
    ptr->next = p->next;

}
struct Node* insertatend(struct Node* head  , int data){
    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->data = data ;
    struct Node*  p = head ;
    while(p->next != NULL){
        p = p->next;

    }
    p->next = ptr ;
    ptr->next = NULL;
    return head;
}


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

  head = insertathead(head , 20);
  head = insertathead(head , 30);
//   while(head != NULL){
//     cout << head->data << endl;
//     head = head->next;
//   }

}