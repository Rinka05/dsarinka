#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Node{
    public:
    int data ;
    Node* next ;
    Node(int data ){
        this->data = data ;
        next = NULL;
    }
};


Node* takeinput_better(){
    int data ; cin >> data ;
    Node * head = NULL;
    Node* tail = NULL;
   
    while(data != -1){
         Node* newNode = new Node(data);
        if(head == NULL){
            head = newNode;
            tail = newNode;
        }
        else {
            tail->next = newNode;
            tail = tail->next;;
        }
        cin >> data ;
    }
    return head ;
}

Node* mergedll(Node* head1 , Node* head2){
    Node* temp1 = head1 ;
    Node* temp2 = head2;
    if(temp1&&temp2 == NULL){
        return NULL;
    }
    if(temp1 ==NULL)return temp2;
    if(temp2==NULL)return temp1;
     Node* fhead;
     Node* ftail;
     if(temp1->data <= temp2->data){
        fhead = temp1;
        ftail = temp1;
        temp1 = temp1->next;
     }
     else{
        fhead = temp2;
        ftail = temp2;
        temp2= temp2->next;
     }
    while(temp1!= NULL && temp2!= NULL){
      if(temp1->data <= temp2->data){
       
       ftail->next = temp1;
       ftail = temp1;
       temp1 = temp1->next;
      }
      else {
          ftail->next = temp2;
          ftail = temp2;
          temp2 = temp2->next;

      }
    }
    while(temp1!= NULL){
     ftail->next = temp1;
    }
    while(temp2!= NULL){
     ftail->next = temp2;
    }
    return fhead;
}

void print(Node* head){
    while(head!= NULL){
        cout << head->data << " ";
        head = head->next;
    }
}

int main(){
  Node* head1 = takeinput_better();
  Node* head2 = takeinput_better();
  Node* head3 = mergedll(head1  , head2);
 print(head3);
 return 0;
}

//recursion
class Solution {
public:
    Node* mergeTwoLists(Node* list1, Node* list2) {
        if(list1==nullptr)return list2;
        if(list2 == nullptr)return list1;
        if(list1->data <= list2->data){
            list1->next = mergeTwoLists(list1->next , list2);
            return list1;
        }
        else {
            list2->next = mergeTwoLists(list1 , list2->next);
            return list2;
        }
    }
};


