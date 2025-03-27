/*
Problem statement
You are given two sorted linked lists. You have to merge them to produce a combined sorted linked list. You need to return the head of the final linked list.

Note:

The given linked lists may or may not be null.
For example:

If the first list is: 1 -> 4 -> 5 -> NULL and the second list is: 2 -> 3 -> 5 -> NULL

The final list would be: 1 -> 2 -> 3 -> 4 -> 5 -> 5 -> NULL
Detailed explanation ( Input/output format, Notes, Images )
Constraints:
1 <= L <= 10^5
1 ≤ data ≤ 10^6 and data != -1

Where L is the number of nodes in either of the two Linked List.

Time Limit: 1 sec
Follow-up:

Try to solve this problem in linear time complexity and constant space complexity.
Sample Input 1:
7 8 -1
1 3 4 6 -1
Sample Output 1:
1 3 4 6 7 8 -1
Explanation of Input 1:
In this testcase, the first list is: 7 -> 8 -> NULL
The second list is: 1 -> 3 -> 4 -> 6 -> NULL
The final list would be: 1 -> 3 -> 4 -> 6 -> 7 -> 8 -> NULL
Sample Input 2:
5 -1
1 3 6 10 -1
Sample Output 2
1 3 5 6 10 -1

*/
#include <bits/stdc++.h>
using namespace std; 

template <typename T>
class Node
{
public:
    T data;
    Node *next;

    Node(T data)
    {
        next = NULL;
        this->data = data;
    }

    ~Node()
    {
        if (next != NULL)
        {
            delete next;
        }
    }
};
Node<int>* solve(Node<int>* first, Node<int>* second)
{
    //if only one element is presnt on list 
    if(first->next==NULL)
    {
        first->next=second;
        return first;
    }
    Node<int>* curr1 = first;
    Node<int>* next1 = curr1->next;
    Node<int>* curr2 = second;
    Node<int>* next2 = curr2->next;

    while (next1 != NULL && curr2 != NULL)
    {
        if ((curr2->data >= curr1->data) && (curr2->data <= next1->data))
        {

            curr1->next = curr2;
            next2 = curr2->next;
            curr2->next = next1; 

            curr1 = curr2;
            curr2 = next2;
        }
        else
        {
            // curr1 and next1 ko aage bhadna hai
            curr1 = next1;
            next1 = next1->next;

            if (next1 == NULL)
            {
                curr1->next = curr2;
                return first;
            }
        }
    }
    return first;
}
Node<int> *sortTwoLists(Node<int> *first, Node<int> *second)
{

    if (first == NULL)
        return second;

    if (second == NULL)
    {
        return first;
    }
    if (first->data <= second->data)
    {
        solve(first, second);
    }
    else
    {
        solve(second, first);
    }
}
// Function to print linked list
void printList(Node<int> *head)
{
    Node<int> *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << "-1" << endl; // Indicating end of list
}

// Function to insert node at the end of the list
void insertNode(Node<int> *&head, int data)
{
    if (head == NULL)
    {
        head = new Node<int>(data);
        return;
    }
    Node<int> *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = new Node<int>(data);
}

int main()
{
    Node<int> *first = NULL;
    Node<int> *second = NULL;

    cout << "Enter the elements of the first linked list (-1 to stop): ";
    while (true)
    {
        int value;
        cin >> value;
        if (value == -1)
            break;
        insertNode(first, value);
    }

    cout << "Enter the elements of the second linked list (-1 to stop): ";
    while (true)
    {
        int value;
        cin >> value;
        if (value == -1)
            break;
        insertNode(second, value);
    }

    cout << "First List: ";
    printList(first);

    cout << "Second List: ";
    printList(second);

    Node<int> *result = sortTwoLists(first, second);

    cout << "Merged Sorted List: ";
    printList(result);

    return 0;
}
