/*
Given a head singly linked list of positive integers. The task is to check if the given linked list is palindrome or not.

Examples:

Input: head: 1 -> 2 -> 1 -> 1 -> 2 -> 1
Output: true
Explanation: The given linked list is 1 -> 2 -> 1 -> 1 -> 2 -> 1 , which is a palindrome and Hence, the output is true.

Input: head: 1 -> 2 -> 3 -> 4
Output: false
Explanation: The given linked list is 1 -> 2 -> 3 -> 4, which is not a palindrome and Hence, the output is false.

Constraints:
1 <= number of nodes <= 105
1 ≤ node->data ≤ 103

Company Tags

*/

//{ Driver Code Starts
#include <algorithm>
#include <bits/stdc++.h>
#include <cmath>
#include <cstdio>
#include <ios>
#include <iostream>
#include <random>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

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

// } Driver Code Ends

/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

class Solution
{
private:
    bool checkPalindrome(vector<int> arr)
    {
        int n = arr.size();
        int s = 0;
        int e = n - 1;

        while (s <= e)
        {
            if (arr[s] != arr[e])
                {
                    return 0;
                }
                s++;
                e--;
            }
            return true;
        }
    

public:
    // Function to check whether the list is palindrome.
    bool isPalindrome(Node *head)
    {
        // Your code here

        vector<int> arr;
        Node *temp = head;
        while (temp != NULL)
        {
            arr.push_back(temp->data);
            temp = temp->next;
        }
      
        return checkPalindrome(arr);
    }
};

//{ Driver Code Starts.

/* Function to print nodes in a given linked list */
void printList(struct Node *head)
{
    struct Node *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        if (n == 0) {
            cout << "empty" << endl;
            continue;
        }

        int value;
        cin >> value;
        Node *head = new Node(value);
        Node *tail = head;

        for (int i = 1; i < n; ++i) {
            cin >> value;
            tail->next = new Node(value);
            tail = tail->next;
        }

        Solution ob;
        if (ob.isPalindrome(head))
            cout << "true" << endl;
        else
            cout << "false" << endl;

        // Clean up to avoid memory leaks
        while (head != NULL) {
            Node *temp = head;
            head = head->next;
            delete temp;
        }
        cout << "~\n";
    }
    return 0;
}


// } Driver Code Ends