#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
    Node(int data, Node *next)
    {
        this->data = data;
        this->next = next;
    }
};
//...it will return head of the reverse list....
Node* reverse1(Node* head)
{
    //..Base Case..
    if(head==NULL || head->next==NULL)
    {
        return head;
    }
    Node* chotaHead=reverse1(head->next);
    head->next->next=head;
    head->next=NULL;

    return chotaHead;
}
Node *reverseLinkedList(Node *head)
{
    // Node *curr = head;
    // Node *prev = NULL;
    // reverse1( head);
    // return head;
    return reverse1(head);

}

void printList(Node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Enter the number of elements in the linked list: ";
    cin >> n;

    Node* head = NULL;
    Node* tail = NULL;

    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        int value;
        cin >> value;
        Node* newNode = new Node(value);
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    cout << "Original list: ";
    printList(head);

    head = reverseLinkedList(head);

    cout << "Reversed list: ";
    printList(head);

    return 0;
}