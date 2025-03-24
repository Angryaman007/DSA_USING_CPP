/*

Problem statement
Given a singly linked list, you have to detect the loop and remove the loop from the linked list, if present. You have to make changes in the given linked list itself and return the updated linked list.

Expected Complexity: Try doing it in O(n) time complexity and O(1) space complexity. Here, n is the number of nodes in the linked list.

Detailed explanation ( Input/output format, Notes, Images )
Constraints:
1 <= N <= 100000.
1 <= ‘VAL’ <= 1000 .

Time limit: 1 sec
Sample Input:
6 2
1 2 3 4 5 6
Sample Output:
1 2 3 4 5 6
Explanation:
For the given input linked list, the last node is connected to the second node as:


*/

#include <bits/stdc++.h>
#include <map>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
    ~Node()
    {
        int value = this->data;
        if (this->next != NULL)
        {
            delete next;
            next = NULL;
        }
        cout << " MEMORY is free for node with data " << value << endl;
    }
};

void insertNode(Node *&tail, int element, int d)
{

    // empty list
    if (tail == NULL)
    {
        Node *newNode = new Node(d);
        tail = newNode;
        newNode->next = newNode;
    }
    else
    {
        // non empty list
        // asuming that the elemene tis present in the list
        Node *curr = tail;

        while (curr->data != element)
        {
            curr = curr->next;
        }
        /// element found ->curr is representing elemtn wala node
        Node *temp = new Node(d);
        temp->next = curr->next;
        curr->next = temp;
    }
}

void print(Node *tail)
{
    Node *temp = tail;
    if (tail == NULL)
    {
        cout << "List is empty " << endl;
        return;
    }
    do
    {
        cout << tail->data << " ";
        tail = tail->next;
    } while (tail != temp);
    cout << endl;
}

void deleteNode(Node *&tail, int value)
{
    // empty list
    if (tail == NULL)
    {
        cout << " list is empty , please check again " << endl;
        return;
    }
    else
    {
        // non empty list
        Node *prev = tail;
        Node *curr = prev->next;
        while (curr ->data != value)
        {
            prev = curr;
            curr = curr->next;
        }
        prev->next = curr->next;
        // 1 node linkes list
        if (curr == prev)
        {
            tail = NULL;
        }
        // 2 node linked list
        else if (tail == curr)
        {
            tail = prev;
        }
        curr->next = NULL;
        delete curr;
    }
}
/*

>>Question that can be asked in this promblem
>>>>Detect cycle in LL
>>>>Remove cycle from LL
>>>>beggning or Start node of loop in LL



Node *removeLoop(Node *head)
{
    // Write your code here.
}
    */
bool isCircularList(Node *head)
{
    // empty list
    if (head == NULL)
    {
        return NULL;
    }
    Node *temp = head->next;
    while(temp != NULL && temp != head)
    {
        temp = temp->next;
    }
    if (temp == head)
    {
        return true;
    }
    return false;
}

bool detectLoop(Node *head)
{
    if (head = NULL)
        return false;
    map<Node *, bool> visited;
    Node *temp = head;
    while (temp != NULL)
    {
        if (visited[temp] == true)
        {
            return true;
        }
        visited[temp] = true;
        temp = temp->next;
    }
    return false;
}