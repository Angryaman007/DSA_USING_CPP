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
    if (head == NULL) // An empty list is circular
        return true;

    Node *slow = head;
    Node *fast = head;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;

        // If a loop is detected
        if (slow == fast)
        {
            // Check if the loop connects back to head
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

int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        int n;
        cin >> n;

        if (n == 0)
        {
            cout << "True" << endl;
            continue;
        }

        int data;
        cin >> data;
        Node *head = new Node(data);
        Node *curr = head;

        for (int i = 1; i < n; i++)
        {
            cin >> data;
            curr->next = new Node(data);
            curr = curr->next;
        }

        int lastNodeLink;
        cin >> lastNodeLink;

        // Link last node to the node with value = lastNodeLink (if exists)
        if (lastNodeLink != -1)
        {
            Node *temp = head;
            while (temp != NULL)
            {
                if (temp->data == lastNodeLink)
                {
                    curr->next = temp;
                    break;
                }
                temp = temp->next;
            }
        }

        cout << (isCircular(head) ? "True" : "False") << endl;
    }

    return 0;
}
