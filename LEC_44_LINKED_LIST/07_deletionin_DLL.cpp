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
//destructor to delet or Free memory 
    ~Node()
    {
        int val=this -> data;
        if(next != NULL)
        {
            delete next;
            next=NULL;
        }
        cout<< "memory free for node with data " <<val<<endl;
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
 /*
void deletNode(int position, Node *&head)
{
    // deleting first or start node
    if (position == 1)
    {
        Node *temp = head;
        temp->next->prev=NULL;
        head=temp->next;
        temp->next=NULL;
        delete temp;
    }

    else
    {
        
       
        // delteting any middle node or last node
        Node *curr = head;
        Node *prev = NULL;

        int cnt = 1;
        while (cnt < position)
        {
            prev = curr;
            curr = curr->next;
            cnt++;
        }
        curr->prev=NULL;
        prev->next=curr->next;
        curr->next==NULL;
        delete curr;
       
    }
}
 */
// Delete a node at a specific position
void deletNode(int position, Node*& head, Node*& tail) {
    // If the list is empty
    if (head == NULL) {
        cout << "List is empty!" << endl;
        return;
    }

    // Deleting the first node
    if (position == 1) {
        Node* temp = head;
        if (head->next != NULL) {
            head = head->next;
            head->prev = NULL;
        } else {
            head = NULL;
            tail = NULL; // If only one node existed
        }
        temp->next = NULL;
        delete temp;
        return;
    }

    // Deleting any middle or last node
    Node* curr = head;
    int cnt = 1;

    // Traverse to the node at 'position'
    while (cnt < position && curr != NULL) {
        curr = curr->next;
        cnt++;
    }

    // If position is invalid
    if (curr == NULL) {
        cout << "Invalid position!" << endl;
        return;
    }

    // If deleting the last node, update the tail pointer
    if (curr->next == NULL) {
        tail = curr->prev;
        tail->next = NULL;
    } else {
        curr->next->prev = curr->prev;
        curr->prev->next = curr->next;
    }

    // Clean up the deleted node
    curr->next = NULL;
    curr->prev = NULL;
    delete curr;
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
    
    deletNode(7,head,tail);
    print(head);
    cout << "head: " << head->data << " tail: " << tail->data << endl;

    return 0;
}