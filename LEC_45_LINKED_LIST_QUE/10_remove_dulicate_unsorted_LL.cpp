/*
Problem statement
You are given a linked list of N nodes. Your task is to remove the duplicate nodes from the linked list such that every element in the linked list occurs only once i.e. in case an element occurs more than once, only keep its first occurrence in the list.

For example :
Assuming the linked list is 3 -> 2 -> 3 -> 4 -> 2 -> 3 -> NULL.

Number ‘2’ and ‘3’ occurs more than once. Hence we remove the duplicates and keep only their first occurrence. So, our list becomes : 3 -> 2 -> 4 -> NULL.
Detailed explanation ( Input/output format, Notes, Images )
Constraints :
1 <= T <= 100
1 <= N <= 10 ^ 4
1 <= data <= 10 ^ 5

Where ‘N’ is the number of nodes in the list and 'data' is the value of list nodes.

Time Limit: 1sec
Sample Input 1 :
2
4 2 5 4 2 2 -1
1 2 1 2 2 2 7 7 -1
Sample Output 1 :
4 2 5 -1
1 2 7 -1
Explanation of Sample Input1 :
For the first test case, the linked list is 4 -> 2 -> 5 -> 4 -> 2 -> 2 -> NULL. Number ‘4’ and ‘2’ occurs more than once. Hence, we remove the duplicates and keep only their first occurrence. So, our list becomes : 4 -> 2 -> 5 -> NULL.

For the second test case, the linked list is 1 -> 2 -> 1 -> 2 -> 2 -> 2 -> 7 -> 7 -> NULL. Number ‘1’, ‘2’ and ‘7’ occurs more than once. Hence, we remove the duplicates and keep only their first occurrence. So, our list becomes : 1 -> 2 -> 7 -> NULL.
Sample Input 2 :
2
3 3 3 3 3 -1
10 20 10 20 30 10 20 30 -1
Sample Output 2 :
3 -1
10 20 30 -1

*/

#include <iostream>
#include <unordered_set>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        this->next = NULL;
    }
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

Node *removeDuplicates(Node *head)
{
    if (head == NULL)
        return NULL;

    unordered_set<int> seen;
    Node *curr = head;
    Node *prev = NULL;

    while (curr != NULL)
    {
        if (seen.find(curr->data) != seen.end())
        {
            // Duplicate found, remove it
            prev->next = curr->next;
            delete curr;
            curr = prev->next;
        }
        else
        {
            // Not a duplicate, add to set and move forward
            seen.insert(curr->data);
            prev = curr;
            curr = curr->next;
        }
    }
    return head;
}

void printList(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << "-1" << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int data;
        cin >> data;
        if (data == -1)
            continue;

        Node *head = new Node(data);
        Node *tail = head;

        while (true)
        {
            cin >> data;
            if (data == -1)
                break;
            tail->next = new Node(data);
            tail = tail->next;
        }

        head = removeDuplicates(head);
        printList(head);

        // Free allocated memory
        Node *temp;
        while (head != NULL)
        {
            temp = head;
            head = head->next;
            delete temp;
        }
    }

    
    return 0;
}
