/*
Problem statement
Given a singly linked list of 'N' nodes. The objective is to determine the middle node of a singly linked list. However, if the list has an even number of nodes, we return the second middle node.

Note:
1. If the list is empty, the function immediately returns None because there is no middle node to find.
2. If the list has only one node, then the only node in the list is trivially the middle node, and the function returns that node.

*/
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

Node* getMiddle(Node* head)
{
    if(head==NULL || head->next==NULL)
    return NULL;

    // 2 nodes needed or not ?
    if(head->next->next==NULL)
    {
        return head->next;
    }
Node* slow =head;
Node* fast= head->next;

while( fast != NULL)
{
    fast =fast->next;
    if(fast !=NULL)
    {
        fast =fast->next;
    }
    slow=slow->next;
}
return slow;
}

//................

int getLength(Node *head)
{
    int len = 0;
    while (head != NULL)
    {
        len++;
        head = head->next;
    }
    return len;
}
Node *findMiddle(Node *head)
{
    return getMiddle(head);
    /*
    int len = getLength(head);
    int ans = (len / 2);
    Node *temp = head;
    int cnt = 0;
    while (cnt < ans)
    {
        temp = temp->next;
        cnt++;
    }
    return temp;
    */
}
int main()
{
    Node *head = NULL;
    Node *tail = NULL;
    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
    {
        int value;
        cin >> value;
        Node *newNode = new Node(value);
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }

    // Displaying the list
    cout << "Linked list: ";
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;

    // Finding and printing the middle node
    Node *middle = findMiddle(head);
    cout << "Middle element: " << middle->data << endl;

    return 0;
}