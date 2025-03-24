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

*/
#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *next;

    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

Node *removeLoop(Node *head) {
    if (head == NULL || head->next == NULL) return head;

    Node *slow = head;
    Node *fast = head;

    // Step 1: Detect the loop
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            // Step 2: Find the start of the loop
            slow = head;
            Node *prev = NULL;
            while (slow != fast) {
                prev = fast;
                slow = slow->next;
                fast = fast->next;
            }

            // Step 3: Remove the loop
            while (fast->next != slow) {
                fast = fast->next;
            }
            fast->next = NULL;
            break;
        }
    }

    return head;
}

// Function to create a loop for testing
void createLoop(Node* head, int position) {
    if (position == 0) return;

    Node* temp = head;
    Node* loopNode = NULL;

    int count = 1;
    while (temp->next != NULL) {
        if (count == position) {
            loopNode = temp;
        }
        temp = temp->next;
        count++;
    }

    if (loopNode != NULL) {
        temp->next = loopNode;
    }
}

// Function to print the linked list
void printList(Node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Create linked list: 1 -> 2 -> 3 -> 4 -> 5 -> 6
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = new Node(6);

    // Create a loop (connecting node 6 to node 2)
    createLoop(head, 2);

    // Remove the loop
    head = removeLoop(head);

    // Print the list after removing the loop
    cout << "Linked list after removing loop: ";
    printList(head);

    return 0;
}
