/*
Problem statement
For a given Singly Linked List of integers, sort the list using the 'Merge Sort' algorithm.

Detailed explanation ( Input/output format, Notes, Images )
Constraints :
1 <= N <= 10^5
1 <= DATA <= 10^9

Where 'DATA' denotes the value of node of Linked List.

Time Limit: 1sec
Sample Input 1 :
1 4 5 2 -1
Sample Output 1 :
1 2 4 5
Sample Input 2 :
10 9 8 7 6 5 4 -1
Sample Output 2 :
4 5 6 7 8 9 10


*/


#include<iostream>
using namespace std;
class node{
    public:
        int data;
        node * next;
        node(int data){
            this->data=data;
            this->next=NULL;
        }
};


node* findMid(node* head){
    node* slow =head;
    node* fast=head->next;

    while( fast != NULL && fast->next !=NULL )
    {
        slow =slow->next;
        fast=fast->next ->next;
    }
    return slow;  
}

node* merge(node* left, node* right)
{
    if(left==NULL)
    return right;

    if(right==NULL)
    return left;
  
    node* ans =new node(-1);
    node* temp=ans;

while( left != NULL && right !=NULL )
{
if(left->data<right->data)
{
    temp->next=left;
    temp=left;
    left=left->next;
}
else{
    temp->next =right;
    temp=right;
    right =right->next;
}
}

while( left !=NULL )
{
    temp->next=left;
    temp=left;
    left=left->next;
}
while(right !=NULL)
{
    temp->next=right;
    temp=right;
    right=right->next;
}
ans=ans->next;
return ans;

}


node* mergeSort(node *head) {
//base case 
if(head ==NULL || head->next==NULL)
{
    return head;
}
// break LL in 2 halfs , after finging mid 
node* mid =findMid(head);

node* left =head;
node* right=mid->next;
mid->next=NULL;


/// now sorting using recursive calls at both halfs
left=mergeSort(left);
right=mergeSort(right);

//merge both left and right halves 
node* result =merge(left,right);

return result;

}
// Function to insert a node at the end of the linked list
void insertAtTail(node*& head, node*& tail, int data) {
    node* newNode = new node(data);
    if (head == NULL) {
        head = newNode;
        tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
}

// Function to print the linked list
void printList(node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// Main function
int main() {
    node* head = NULL;
    node* tail = NULL;

    // Insert elements into the linked list
    insertAtTail(head, tail, 4);
    insertAtTail(head, tail, 2);
    insertAtTail(head, tail, 1);
    insertAtTail(head, tail, 5);
    insertAtTail(head, tail, 3);

    cout << "Original Linked List: ";
    printList(head);

    // Sorting the linked list using merge sort
    head = mergeSort(head);

    cout << "Sorted Linked List: ";
    printList(head);

    return 0;
}
