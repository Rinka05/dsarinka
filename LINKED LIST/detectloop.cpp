#include <bits/stdc++.h>
#include <iostream>
#include "input.cpp"
using namespace std;

bool detectloop(Node* head){
    Node* fast = head ;
    Node* slow = head;
    while(fast != NULL && fast->next != NULL){
        fast = fast->next->next;
        slow = slow->next;
        if(fast == slow){
            return true ;
        }
    }
    return false ;
}

bool detectloopmap(Node* head){
    if(head == NULL || head->next == NULL){
        return 0;
    }
    map<Node*, bool>visited;
    Node* temp = head;
    while(temp!= NULL){
        if(visited[temp]==1){
            return 1;
        }
        visited[temp] =1;
        temp = temp->next;
    }
    return 0;
}

int main(){
    Node* head = takeinput_better();
    bool ans = detectloop(head);
    if(ans){
        cout << "yES"<< endl;
    }
    else{
        cout <<"NO"<< endl;
    }
}