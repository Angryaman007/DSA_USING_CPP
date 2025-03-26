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

Node *sortList(Node *head)
{
    // Write your code here.
    int zeroCount = 0;
    int oneCount = 0;
    int twoCount = 0;

    Node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == 0)
            zeroCount++;
        else if (temp->data == 1)
            oneCount++;
        else if (temp->data == 2)
            twoCount++;
        temp = temp->next;
    }
    temp = head;
    while (temp != NULL)
    {
        if (zeroCount != 0)
        {
            temp->data = 0;
            zeroCount--;
        }
        else if (oneCount != 0)
        {
            temp->data = 1;
            oneCount--;
        }
        else if (twoCount != 0)
        {
            temp->data = 2;
            twoCount--;
        }
        temp = temp->next;
    }
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
