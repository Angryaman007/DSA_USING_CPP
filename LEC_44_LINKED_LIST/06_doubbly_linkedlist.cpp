#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* prev;
    Node* next;
    
    // Constructor
    Node(int d) {
        this->data = d;
        this->prev = NULL;
        this->next = NULL;
    }
};

// Traversing the linked list
void print(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Get length of the linked list
int getLength(Node* head) {
    int len = 0;
    Node* temp = head;
    while (temp != NULL) {
        len++;
        temp = temp->next;
    }
    return len;
}

// Insert at head
void insertAtHead(Node*& head, Node*& tail, int d) {
    Node* temp = new Node(d);
    if (head == NULL) {
        head = temp;
        tail = temp;
    } else {
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
}

// Insert at tail
void insertAtTail(Node*& tail, Node*& head, int d) {
    Node* temp = new Node(d);
    if (tail == NULL) {
        tail = temp;
        head = temp;
    } else {
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }
}

// Insert at any position
void insertAtPosition(Node*& tail, Node*& head, int position, int d) {
    if (position == 1) {
        insertAtHead(head, tail, d);
        return;
    }
    
    Node* temp = head;
    int cnt = 1;
    while (cnt < position - 1 && temp->next != NULL) {
        temp = temp->next;
        cnt++;
    }
    
    // Insert at the last position
    if (temp->next == NULL) {
        insertAtTail(tail, head, d);
        return;
    }
    
    Node* nodeToInsert = new Node(d);
    nodeToInsert->next = temp->next;
    temp->next->prev = nodeToInsert;
    temp->next = nodeToInsert;
    nodeToInsert->prev = temp;
}

int main() {
    Node* head = NULL;
    Node* tail = NULL;
    
    print(head);
    
    insertAtHead(head, tail, 11);
    print(head);
    cout << "head: " << head->data << " tail: " << tail->data << endl;
    
    insertAtHead(head, tail, 13);
    print(head);
    cout << "head: " << head->data << " tail: " << tail->data << endl;
    
    insertAtHead(head, tail, 8);
    print(head);
    cout << "head: " << head->data << " tail: " << tail->data << endl;
    
    insertAtTail(tail, head, 25);
    print(head);
    cout << "head: " << head->data << " tail: " << tail->data << endl;
    
    insertAtPosition(tail, head, 2, 100);
    print(head);
    cout << "head: " << head->data << " tail: " << tail->data << endl;
    
    insertAtPosition(tail, head, 1, 69);
    print(head);
    cout << "head: " << head->data << " tail: " << tail->data << endl;
    
    insertAtPosition(tail, head, 8, 117);
    print(head);
    cout << "head: " << head->data << " tail: " << tail->data << endl;
    
    return 0;
}