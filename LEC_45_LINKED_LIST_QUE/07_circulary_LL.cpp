/*
Problem statement
You are given the head of a linked list containing integers, You need to find out whether the given linked list is circular or not.

Note :

1. A linked list is said to be circular if it has no node having its next pointer equal to NULL and all the nodes form a circle i.e. the next pointer of last node points to the first node.
2. An empty linked will also be considered as circular.
3. All the integers in the linked list are unique.
4. In the input, the next pointer of a node with i’th integer is linked to the node with data (i+1)’th integer (If (i+1)’th node exists). If there is no such (i+1)’th integer then the next pointer of such node is set to NULL.
Detailed explanation ( Input/output format, Notes, Images )
Constraints :
1 <= T <= 10 ^ 2
1 <= D <= 10 ^ 6, here D is data stored in the node.
0 <= N <= 10 ^ 4

Time Limit: 1 sec
Sample Input 1 :
1
5
1 2 3 4 1
Sample Output 1 :
True

*/

#include <bits/stdc++.h>
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
};

bool isCircular(Node *head)
{
    if (head == NULL) // Empty list is not circular
        return false;

    Node *slow = head;
    Node *fast = head;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
        {
            // Check if the cycle points back to the head
            Node *temp = slow;
            do
            {
                if (temp == head)
                    return true;
                temp = temp->next;
            } while (temp != slow);

            return false;
        }
    }

    return false;
}

// Example usage:
int main()
{
    Node *head = new Node(1);
    Node *second = new Node(2);
    Node *third = new Node(7);
    Node *fourth = new Node(4);
    Node *fifth = new Node(8);
    Node *sixth = new Node(3);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = sixth;
    // sixth->next = head; // Uncomment to make it circular

    if (isCircular(head))
        cout << "The list is circular.\n";
    else
        cout << "The list is not circular.\n";

    return 0;
}
