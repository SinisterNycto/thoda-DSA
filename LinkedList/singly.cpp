#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node* next;
    // for creating a node with next ptr
    Node(int data1, Node* next1){
        data = data1;
        next = next1;
    }
    // for creating a node without the need of next ptr
    Node(int data1){
        data = data1;
        next = NULL;
    }
};

void printList(Node* head){
    Node* temp = head;

    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
}

int main() {
    Node* head = new Node(5);
    head->next = new Node(3);
    head->next->next = new Node(4);
    printList(head);
    
    return 0;
}
