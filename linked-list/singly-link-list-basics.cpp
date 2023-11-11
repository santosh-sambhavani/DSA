#include <bits/stdc++.h>
using namespace std;

class Node {
    public: 
    int data;
    Node* next;
        
    Node(int data) {
        this -> data = data;
        this -> next = NULL;
    }
    
    ~Node() {
        int val = this -> data;
        if(this->next != NULL) {
            delete next;
            this->next = NULL;
        }
        cout << "\n [DELETION] memory is free for node with data " << val;
    }
};

void deleteAtBegin(Node* &head) {
    Node* temp = head;
    head = head -> next;
    temp -> next = NULL;
    delete temp;
}

void deleteAtPosition(Node* &head, int position, Node* &tail) {
    if(position == 1) {
        deleteAtBegin(head);
        return ;
    }
    Node* current = head;
    Node* prev = NULL;
    int currentPosition = 1;
    
    while(currentPosition != position) {
        prev = current;
        current = current -> next;
        currentPosition++;
    }
    
    if(current -> next == NULL) {
        tail = prev;
    }
    
    prev -> next = current -> next;
    current -> next = NULL;
    delete current;
}

void deleteValue(Node* &head, int value, Node* &tail) {
    if(head->data == value) {
        deleteAtBegin(head);
        return ;
    }
    Node* current = head;
    Node* prev = NULL;

    while(current->data != value) {
        prev = current;
        current = current -> next;
        if(current == NULL) return ;
    }
    
    if(current -> next == NULL) {
        tail = prev;
    }
    
    prev -> next = current -> next;
    current -> next = NULL;
    delete current;
}

void insertAtBegin(Node* &head, int data) {
    Node* temp = new Node(data);
    temp -> next = head;
    head = temp;
}

void insertAtEnd(Node* &tail, int data) {
    Node* temp = new Node(data);
    tail -> next = temp;
    tail = temp;
}

void insertAtPosition(Node* &head, int data, int position) {
    if(position == 1) {
        insertAtBegin(head, data);
        return ;
    } 
    Node* temp = head;
    int currentPosition = 1;
    
    while(currentPosition != position) {
        temp = temp -> next;
        currentPosition++;
    }
    
    if(temp -> next == NULL) {
        insertAtEnd(temp, data);
        return ;
    }
    
    Node* newNode = new Node(data);
    newNode -> next = temp -> next;
    temp -> next = newNode;
}

void print(Node* &head) {
    Node* temp = head;
    cout << "\nLinked List is: ";
    while(temp != NULL){
        cout << " " << temp -> data;
        temp = temp->next;
    }
}

int main() {
    
    Node* head = new Node(10);
    Node* tail = head;
    
    // insertAtBegin(head, 20);
    // insertAtBegin(head, 30);
    
    insertAtEnd(tail, 20);
    insertAtEnd(tail, 30);
    insertAtEnd(tail, 40);
    insertAtEnd(tail, 50);
    insertAtEnd(tail, 60);
    
    // print(head);
    
    // insertAtPosition(head, 34, 1);
    // insertAtPosition(head, 87, 4);
    
    // deleteAtPosition(head, 4, tail);
    
    // deleteValue(head, 30, tail);
    // deleteValue(head, 10, tail);
    deleteValue(head, 100, tail);
    
    print(head);
    
    cout << "\n ==== Everything working fine ==== ";
        
    return 0;
}
