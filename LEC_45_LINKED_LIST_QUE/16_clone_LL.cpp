/*
You are given a special linked list with n nodes where each node has two pointers a next pointer that points to the next node of the singly linked list, and a random pointer that points to the random node of the linked list.

Construct a copy of this linked list. The copy should consist of the same number of new nodes, where each new node has the value corresponding to its original node. Both the next and random pointer of the new nodes should point to new nodes in the copied list, such that it also represent the same list state. None of the pointers in the new list should point to nodes in the original list.

Return the head of the copied linked list.

NOTE : Original linked list should remain unchanged.

Examples:

Input: head = [[1, 3], [3, 3], [5, NULL], [9, 3]]

Output: head = [[1, 3], [3, 3], [5, NULL], [9, 3]]
Explanation:
Node 1 points to Node 2 as its NEXT and Node 3 as its RANDOM.
Node 2 points to Node 3 as its NEXT and Node 3 as its RANDOM.
Node 3 points to Node 4 as its NEXT and NULL as its RANDOM.
Node 4 points to NULL as its NEXT and Node 3 as its RANDOM.
Input: head = [[1, 3], [2, 1], [3, 5], [4, 3], [5, 2]]


Output: head = [[1, 3], [2, 1], [3, 5], [4, 3], [5, 2]]
Explanation:
Node 1 points to Node 2 as its NEXT and Node 3 as its RANDOM.
Node 2 points to Node 3 as its NEXT and Node 1 as its RANDOM.
Node 3 points to Node 4 as its NEXT and Node 5 as its RANDOM.
Node 4 points to Node 5 as its NEXT and Node 3 as its RANDOM.
Node 5 points to NULL as its NEXT and Node 2 as its RANDOM.
Input: head = [[7, NULL], [7, NULL]]
Output: head = [[7, NULL], [7, NULL]]
Explanation:
Node 1 points to Node 2 as its NEXT and NULL as its RANDOM.
Node 2 points to NULL as its NEXT and NULL as its RANDOM.*/

//{ Driver Code Starts
#include <bits/stdc++.h>

#include <iostream>
#include <map>
#include <sstream>
#include <vector>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node *random;

    Node(int x)
    {
        data = x;
        next = NULL;
        random = NULL;
    }
};

void print(Node *root)
{
    map<Node *, int> link;
    Node *temp = root;
    for (int i = 0; temp != NULL; i++)
    {
        link[temp] = i;
        temp = temp->next;
    }
    temp = root;
    cout << "[";
    while (temp->next != NULL)
    {
        if (!temp->random)
        {
            cout << "[" << temp->data << ", "
                 << "NULL"
                 << "], ";
        }
        else
            cout << "[" << temp->data << ", " << link[temp->random] + 1 << "], ";
        temp = temp->next;
    }
    if (!temp->random)
    {
        cout << "[" << temp->data << ", "
             << "NULL"
             << "]]\n";
    }
    else
        cout << "[" << temp->data << ", " << link[temp->random] + 1 << "]]\n";
}

bool validation(Node *res, map<Node *, int> &orgAddress)
{
    Node *temp = res;
    for (int i = 0; temp != NULL; i++)
    {
        if (orgAddress.find(temp) != orgAddress.end())
        {
            return false;
        }
        if (orgAddress.find(temp->random) != orgAddress.end())
        {
            return false;
        }
        temp = temp->next;
    }
    return true;
}

Node *buildLinkedList(vector<pair<int, int>> &v, map<Node *, int> &orgAddress)
{
    vector<Node *> address(v.size());
    Node *head = new Node(v[0].first);
    address[0] = head;
    Node *temp = head;
    orgAddress[head] = 0;
    for (int i = 1; i < v.size(); i++)
    {
        Node *newNode = new Node(v[i].first);
        orgAddress[newNode] = i;
        address[i] = newNode;
        temp->next = newNode;
        temp = temp->next;
    }
    temp = head;
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i].second != -1)
        {
            temp->random = address[v[i].second - 1];
        }
        temp = temp->next;
    }

    return head;
}

bool validateInput(map<Node *, int> &orgAddress, Node *head, vector<pair<int, int>> &v)
{
    vector<Node *> address(v.size());
    Node *temp = head;
    for (int i = 0; i < v.size(); i++)
    {
        if (orgAddress.find(temp) == orgAddress.end() || orgAddress[temp] != i)
        {
            return false;
        }
        address[i] = temp;
        temp = temp->next;
    }
    if (temp != NULL)
    {
        return false;
    }
    temp = head;
    for (int i = 0; i < v.size(); i++)
    {
        int value = v[i].first;
        int randomIndex = v[i].second;

        if (randomIndex == -1)
        {
            if (temp->random != NULL)
            {
                return false;
            }
        }
        else
        {
            Node *tempNode = address[randomIndex - 1];
            if (temp->random != tempNode)
            {
                return false;
            }
        }
        temp = temp->next;
    }
    return true;
}

// } Driver Code Ends

/* Link list Node
struct Node {
    int data;
    Node *next;
    Node *random;

    Node(int x) {
        data = x;
        next = NULL;
        random = NULL;
    }
};*/

class Solution
{
private:
    void insertAtTail(Node *&head, Node *&tail, int d)
    {
        Node *newNode = new Node(d);
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
            return;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }

public:
    Node *cloneLinkedList(Node *head)
    {
        // Write your code here

        // step 1: create a clone list
        Node *cloneHead = NULL;
        Node *cloneTail = NULL;

        Node *temp = head;

        while (temp != NULL)
        {
            insertAtTail(cloneHead, cloneTail, temp->data);
            temp = temp->next;
        }
        //// step 2 : create a map
        unordered_map<Node *, Node *> oldToNewNode;

        Node *originalNode = head;
        Node *cloneNode = cloneHead;
        while (originalNode != NULL && cloneNode != NULL)
        {
            oldToNewNode[originalNode] = cloneNode;
            originalNode = originalNode->next;
            cloneNode = cloneNode->next;
        }
        originalNode = head;
        cloneNode = cloneHead;

        while (originalNode != NULL)
        {
            cloneNode->random = oldToNewNode[originalNode->random];
            originalNode = originalNode->next;
            cloneNode = cloneNode->next;
        }
        return cloneHead;
    }
};

//{ Driver Code Starts.

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        vector<pair<int, int>> v(n); // node data, random node number
        for (int i = 0; i < n; i++)
        {
            int x;
            string y;
            cin >> x >> y;
            if (y == "NULL" || y == "N" || y == "null" || y == "n" || y == "Null")
            {
                v[i] = {x, -1};
            }
            else
            {
                v[i] = {x, stoi(y)};
            }
        }
        map<Node *, int> orgAddress;
        Node *head = buildLinkedList(v, orgAddress);

        Solution ob;
        Node *res = ob.cloneLinkedList(head);
        // check if input modified.
        if (validateInput(orgAddress, head, v))
        {
            if (validation(res, orgAddress))
            {
                print(res);
            }
            else
            {
                cout << "Pointing to the original list\n";
            }
        }
        else
        {
            cout << "Input list modified\n";
        }
        cout << "~\n";
    }
    return 0;
}
// } Driver Code Ends
