/*

Problem statement
A doubly-linked list is a data structure that consists of sequentially linked nodes, and the nodes have reference to both the previous and the next nodes in the sequence of nodes.



You are given a sorted doubly linked list of size 'n'.



Remove all the duplicate nodes present in the linked list.



Example :
Input: Linked List: 1 <-> 2 <-> 2 <-> 2 <-> 3

Output: Modified Linked List: 1 <-> 2 <-> 3

Explanation: We will delete the duplicate values ‘2’ present in the linked list.


Detailed explanation ( Input/output format, Notes, Images )
Sample Input 1 :
5
1 2 2 2 3


Sample Output 1 :
1 2 3


Explanation For Sample Input 1 :
We will delete the duplicate values ‘2’ present in the linked list.


Sample Input 2 :
4
1 2 3 4


Sample Output 2 :
1 2 3 4


Explanation For Sample Input 2 :
The list contains no duplicates, so the final list is unchanged.


Expected time complexity :
The expected time complexity is O('n').


Constraints :
1 <= 'n' <= 10^5
1 <= 'data' in any node <= 10^6

Time limit: 1 sec

*/

#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *prev;
    Node *next;
    Node()
    {
        this->data = 0;
        this->prev = NULL;
        this->next = NULL;
    }
    Node(int data)
    {
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }
    Node(int data, Node *next, Node *prev)
    {
        this->data = data;
        this->prev = prev;
        this->next = next;
    }
};

Node *removeDuplicates(Node *head)
{
    // Write your code here
    // empty list
    if (head == NULL)
        return NULL;

    // NON empty list
    Node *curr = head;
    while (curr != NULL)
    {
        if ((curr->next != NULL) && curr->data == curr->next->data)
        {
            Node *next_next = curr->next->next;
            Node *nodeToDelete = curr->next;
            delete (nodeToDelete);
            curr->next = next_next;
        }
        else
        { // not equal
            curr = curr->next;
        }
    }
    return head;
}
int main()
{
    // Creating a sample doubly linked list with duplicates: 1 <-> 1 <-> 2 <-> 3 <-> 3
    Node *head = new Node(1);
    head->next = new Node(1, new Node(2, new Node(3, new Node(3, NULL, NULL), NULL), NULL), NULL);
    head->next->prev = head;
    head->next->next->prev = head->next;
    head->next->next->next->prev = head->next->next;
    head->next->next->next->next->prev = head->next->next->next;

    cout << "Original list: ";
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;

    // Removing duplicates
    head = removeDuplicates(head);

    cout << "List after removing duplicates: ";
    temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;

    // Free allocated memory
    temp = head;
    while (temp != NULL)
    {
        Node *next = temp->next;
        delete temp;
        temp = next;
    }

    return 0;
}
