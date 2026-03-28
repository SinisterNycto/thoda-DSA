#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node* next;
    Node* prev;

    Node(int data1, Node* next1, Node* prev1){
        data = data1;
        next = next1;
        prev = prev1;
    }
    
    Node(int data1){
        data = data1;
        next = NULL;
        prev = NULL;
    }
};

Node* arrToDLL(vector<int>& arr){
    if(arr.size() == 0) return NULL;
    Node* head = new Node(arr[0]);
    // prev node
    Node* back = head;

    for(int i = 1; i < arr.size(); i++){
        Node* temp = new Node(arr[i], NULL, back); // next = null, prev = back
        back->next = temp;
        back = temp;
    }

    return head;
}

void printList(Node* head){
    Node* temp = head;

    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
}

int main() {
    vector<int> arr = {12, 5, 7, 8};
    Node* head = arrToDLL(arr);
    printList(head);
    
    return 0;
}
