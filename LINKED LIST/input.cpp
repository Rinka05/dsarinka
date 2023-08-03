#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next ;
    Node(int data){
        this->data = data;
        this->next = NULL;
    }

    ~Node(){}
};


//o(n*n)
Node* takeinput(){
  int data ;
  cin >> data ;
  Node * head = NULL;
  while(data != -1){
    // we should allocate this node dynamically only
    // to save the values after next iteration
    Node* newNode = new Node(data);
    if(head == NULL){
        head = newNode;
    }
    else{
        Node *temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newNode;
    }
    cin >> data;
  }
  return head;
}
void print(Node* head){
    Node* temp = head;
    while(temp!= NULL){
        cout << temp->data<< " ";
        temp= temp->next;
    }
}



// 
Node*takeinput_better(){
    int data ;
     cin>>data;
     Node* head = NULL;
     Node* tail = NULL;
     while(data != -1){
        // Node(10);

        Node* newNode = new Node(data);
        if(head ==NULL){
            head = newNode;
            tail = newNode;
        }
        else {
            tail->next = newNode;
            tail = tail->next;
        }
        cin>>data;
     }
     return head;
    


}

// int main(){
//  Node* head1 = takeinput_better();

// }













