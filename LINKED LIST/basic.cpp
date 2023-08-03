#include <bits/stdc++.h>
#include <iostream>
using namespace std;


class Node{
    public:
    int data ;
    Node*next;

    Node(int data){
        this->data = data ;
        this->next = NULL;
    }
};

void print(Node* head){
    Node* temp = head;
    while(temp!= NULL){
        cout << temp->data <<" ";
        temp = temp->next;
    }
    cout << endl;
}
void increment(Node*head){
    Node* temp  = head ;
    while(temp!= NULL){
        temp->data ++;
        temp = temp->next;
    }
}


int main(){
    // dynamic
 Node* node1 = new Node(10);
 Node* node2 = new Node(20);
 //static
 Node node3(23);

 node1->next = node2;
increment(node1);
print(node1);
}










// output 11,21
// if we make more nodes and call function from node2 instead of head
// it wont give any result 
// we cannot access pointers randomly 