#include <bits/stdc++.h>
#include <iostream>
#include "input.cpp"
using namespace std;

Node* reversell(Node* head){
    if(head == NULL || head->next == NULL){
        return head;
    }
    Node *smallans = reversell(head->next);
    Node* temp = smallans;
    while(temp->next !=NULL){
        temp = temp->next;
    }
    temp->next = head;
    head->next = NULL;
    return smallans;
}



int main(){
 Node* head1 = takeinput_better();
 print(head1);
cout << endl;
 Node* head2 = reversell(head1);
  print(head2);


}