/*

Problem statement
Given a linked list of 'N' nodes, where each node has an integer value that can be 0, 1, or 2. You need to sort the linked list in non-decreasing order and the return the head of the sorted list.



Example:
Given linked list is 1 -> 0 -> 2 -> 1 -> 2.
The sorted list for the given linked list will be 0 -> 1 -> 1 -> 2 -> 2.


Detailed explanation ( Input/output format, Notes, Images )
Sample Input 1:
7
1 0 2 1 0 2 1


Sample Output 1:
0 0 1 1 1 2 2


Explanation Of Sample Input 1:
Input: 1 -> 0 -> 2 -> 1 -> 0 -> 2 -> 1

Output: 0 -> 0 -> 1 -> 1 -> 1 -> 2 -> 2

Explanation:
In this example, the original linked list contains two 0s, three 1s, and two 2s. The sorted linked list has all the 0s at the beginning, followed by all the 1s, and finally, all the 2s at the end.


>>>>>>> DATA REPLACEMNT IS NOT ALLOWED <<<<<<<<<<<<


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
void insertAtTail(Node* &tail, Node* curr){
    tail->next=curr;
    tail=curr;
}
Node* sortList(Node *head)
 {
    Node* zeroHead=new Node(-1);
    Node* zeroTail=zeroHead;
    Node* oneHead=new Node(-1);
    Node* oneTail=oneHead;
    Node* twoHead=new Node(-1);
    Node* twoTail=twoHead;


    Node* curr=head;
// Create a seprate list for 0s 1s and 2s 
    while(curr!=NULL)
    {
        int value =curr->data;
        if(value==0)
        {
            insertAtTail(zeroTail,curr);
        
        }else if(value==1)
        {
            insertAtTail(oneTail,curr);

        }
        else if(value ==2)
        {
            insertAtTail(twoTail,curr);
        }
        curr=curr->next;
    }
    // merge the ponters 

    if(oneHead->next != NULL)
    {
        zeroTail->next=oneHead->next;
    }
     else{
        //is list ->empty
        zeroTail->next =twoHead->next;
     }
     oneTail->next=twoHead->next;
     twoTail->next=NULL;

     //setup head 
     head=zeroHead->next;


     //delete dummy nodes 
     delete zeroHead;
     delete oneHead;
     delete twoHead;

return head;
 }

// Function to print linked list
void printList(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Function to insert node at the end of the list
void insertNode(Node *&head, int data)
{
    if (head == NULL)
    {
        head = new Node(data);
        return;
    }
    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = new Node(data);
}

int main()
{
    Node *head = NULL;

    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    cout << "Enter the elements (0, 1, or 2): ";
    for (int i = 0; i < n; i++)
    {
        int value;
        cin >> value;
        insertNode(head, value);
    }

    cout << "Original List: ";
    printList(head);

    head = sortList(head);

    cout << "Sorted List: ";
    printList(head);

    return 0;
}
