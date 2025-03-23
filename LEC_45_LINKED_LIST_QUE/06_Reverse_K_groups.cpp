/*

You are given a linked list of 'n' nodes and an integer 'k', where 'k' is less than or equal to 'n'.



Your task is to reverse the order of each group of 'k' consecutive nodes, if 'n' is not divisible by 'k', then the last group of nodes should remain unchanged.



For example, if the linked list is 1->2->3->4->5, and 'k' is 3, we have to reverse the first three elements, and leave the last two elements unchanged. Thus, the final linked list being 3->2->1->4->5.



Implement a function that performs this reversal, and returns the head of the modified linked list.



Example:
Input: 'list' = [1, 2, 3, 4], 'k' = 2

Output: 2 1 4 3

Explanation:
We have to reverse the given list 'k' at a time, which is 2 in this case. So we reverse the first 2 elements then the next 2 elements, giving us 2->1->4->3.


Note:
All the node values will be distinct.


Detailed explanation ( Input/output format, Notes, Images )
Sample Input 1:
6
5 4 3 7 9 2
4


Sample Output 1:
7 3 4 5 9 2


Explanation of the Sample Input 1:
For the given test case, we reverse the nodes in groups of four. But for the last 2 elements, we cannot form a group of four, so leave them as they are. The linked list becomes 7->3->4->5->9->2. Hence the output is 7 3 4 5 9 2


Sample Input 2:
4
4 3 2 8
4


Sample Output 2:
8 2 3 4


Expected Time Complexity:
Try to solve this in O(n).


Expected Space Complexity:
Try to solve this using O(1) extra space.


Constraints:
1 <= n <= 10^4
1 <= k <= n

Time Limit: 1 sec
 
*/
#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node() : data(0), next(nullptr) {}
    Node(int x) : data(x), next(nullptr) {}
    Node(int x, Node *next) : data(x), next(next) {}
};

Node *kReverse(Node *head, int k)
{
    if (head == NULL)
    {
        return NULL;
    }

    // Step 1: Reverse first k nodes + Count remaining nodes simultaneously
    Node *next = NULL;
    Node *curr = head;
    Node *prev = NULL;
    int count = 0;
    int remaining = 0;

    for (Node *temp = head; temp != NULL; temp = temp->next)
        remaining++; // Count remaining nodes

    while (curr != NULL && count < k)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
        remaining--;
    }

    // Step 2: Direct recursion or connection based on remaining nodes
    head->next = (remaining >= k) ? kReverse(next, k) : next;

    // Step 3: Return new head of the reversed list
    return prev;
}
int main()
{
    Node *head = NULL;
    int n, k;

    cout << "Enter number of elements in the linked list: ";
    cin >> n;

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
    {
        int val;
        cin >> val;
        if (head == NULL)
        {
            head = new Node(val);
        }
        else
        {
            Node *temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = new Node(val);
        }
    }

    cout << "Enter value of k: ";
    cin >> k;

    cout << "Original List: ";
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;

    head = kReverse(head, k);

    cout << "Modified List: ";
    temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;

    return 0;
}
