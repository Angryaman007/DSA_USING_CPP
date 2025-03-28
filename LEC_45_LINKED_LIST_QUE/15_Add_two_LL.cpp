/*
Given the head of two singly linked lists num1 and num2 representing two non-negative integers. The task is to return the head of the linked list representing the sum of these two numbers.

For example, num1 represented by the linked list : 1 -> 9 -> 0, similarly num2 represented by the linked list: 2 -> 5. Sum of these two numbers is represented by 2 -> 1 -> 5.

Note: There can be leading zeros in the input lists, but there should not be any leading zeros in the output list.

Examples:

Input: num1 = 4 - > 5, num2 = 3 -> 4 -> 5
Output:  3 -> 9 -> 0

Explanation: Given numbers are 45 and 345. There sum is 390.
Input: num1 = 0 -> 0 -> 6 -> 3, num2 = 0 -> 7
Output: 7 -> 0

Explanation: Given numbers are 63 and 7. There sum is 70.
Constraints:
1 <= size of both linked lists <= 106
0 <= elements of both linked lists <= 9


*/
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

/* Linked list Node */
struct Node
{
    int data;
    struct Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

Node *buildList()
{
    vector<int> arr;
    string input;
    getline(cin, input);
    stringstream ss(input);
    int number;
    while (ss >> number)
    {
        arr.push_back(number);
    }
    if (arr.empty())
    {
        return NULL;
    }
    int val = arr[0];
    int size = arr.size();

    Node *head = new Node(val);
    Node *tail = head;

    for (int i = 1; i < size; i++)
    {
        val = arr[i];
        tail->next = new Node(val);
        tail = tail->next;
    }

    return head;
}

void printList(Node *n)
{
    while (n)
    {
        cout << n->data << " ";
        n = n->next;
    }
    cout << endl;
}

class Solution {
    private:
    Node *reverse(Node *head)
    {
        Node *curr = head;
        Node *prev = NULL;
        Node *next = NULL;
        while (curr != NULL)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    void insertAtTail( Node* &head,  Node* &tail, int val)
    {
        Node* temp = new Node(val);
        if (head == NULL)
        {
            head = temp;
            tail = temp;
        }
        else
        {
            tail->next = temp;
            tail = temp;
        }
    }

    struct Node *add(struct Node *first, struct Node *second)
    {
        int carry = 0;
        Node *ansHead = NULL;
        Node *ansTail = NULL;

        // ✅ Single while loop to handle all cases at once
        while (first != NULL || second != NULL || carry != 0)
        {
            int val1 = (first != NULL) ? first->data : 0;
            int val2 = (second != NULL) ? second->data : 0;

            int sum = carry + val1 + val2;
            int digit = sum % 10;

            insertAtTail(ansHead, ansTail, digit);
            carry = sum / 10;

            if (first != NULL) first = first->next;
            if (second != NULL) second = second->next;
        }
    
        return ansHead;
    }

    Node *removeLeadingZeros(Node *head) 
    {
        while (head != NULL && head->data == 0) 
        {
            Node *temp = head;
            head = head->next;
            delete temp;
        }
        if (head == NULL) return new Node(0);
        return head;
    }

  public:
   struct Node *addTwoLists(struct Node* first,struct Node* second)
    {
        // ✅ Step 1: Reverse both input lists
        first = reverse(first);
        second = reverse(second);

        // ✅ Step 2: Add both linked lists
        Node* ans = add(first, second);

        // ✅ Step 3: Reverse the result list to restore correct order
        ans = reverse(ans);

        // ✅ Step 4: Remove leading zeros from the result
        ans = removeLeadingZeros(ans);

        return ans;
    }
};

int main()
{
    int t;
    cin >> t;
    cin.ignore(); // ✅ Clears buffer

    while (t--)
    {
        Node *num1 = buildList();
        Node *num2 = buildList();

        Solution ob;
        Node *res = ob.addTwoLists(num1, num2);
        printList(res);
    }
    return 0;
}
