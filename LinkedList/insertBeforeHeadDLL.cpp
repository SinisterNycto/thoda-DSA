#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    int val;
    Node* next;
    Node* prev;

    Node(int val1, Node* next1, Node* prev1){
        val = val1;
        next = next1;
        prev = prev1;
    }

    Node(int val1){
        val = val1;
        next = NULL;
        prev = NULL;
    }
};

Node* arrToDLL(vector<int>& arr){
    if(arr.size() == 0){
        return NULL;
    }

    Node* head = new Node(arr[0]);
    Node* back = head;
    for(int i = 1; i < arr.size(); i++){
        Node* temp = new Node(arr[i], NULL, head);
        back->next = temp;
        back = temp;
    }

    return head;
}

Node* insertBeforeHead(Node* head, int val){
    if(head == NULL){
        return new Node(val);
    }

  // three constructor parameters, next of newHead is head, prev of newHead is NULL
    Node* newHead = new Node(val, head, NULL);
    head->prev = newHead;

    return newHead;
}

void print(Node* head){
    while(head != NULL){
        cout << head->val << " ";
        head = head->next;
    }
}

int main() {
    vector<int> arr = {12, 5, 4, 3};
    Node* head = arrToDLL(arr);
    head = insertBeforeHead(head, 14);
    print(head);

    return 0;
}
