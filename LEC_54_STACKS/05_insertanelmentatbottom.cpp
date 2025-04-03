/*
Problem statement
You are given a stack/deque of integers 'MY-STACK' and an integer ‘X’. Your task is to insert ‘X’ to the bottom of ‘MY-STACK’ and return the updated stack/deque.

Note :
If ‘MY_STACK’ = [7, 1, 4, 5], then the first element represents the element at the bottom of the stack and the last element represents the element at the top of the stack.
For Example :
Let ‘MY_STACK’ = [7, 1, 4, 5] and ‘X’ = 9. So, ‘MY_STACK’ after insertion becomes [9, 7, 1, 4, 5].


*/

#include <iostream>
#include <stack>
using namespace std;

// Recursive function to insert element at the bottom
void solve(stack<int>& s, int x) {
    // Base case: If stack is empty, push x and return
    if (s.empty()) {
        s.push(x);
        return;
    }

    int num = s.top();
    s.pop();

    // Recursive call
    solve(s, x);

    // Push the previous element back
    s.push(num);
}

// Function to push an element at the bottom of the stack
stack<int> pushAtBottom(stack<int>& myStack, int x) {
    solve(myStack, x);
    return myStack;
}

// Function to print the stack
void printStack(stack<int> s) {
    stack<int> temp;
    
    // Reverse the stack to print in correct order
    while (!s.empty()) {
        temp.push(s.top());
        s.pop();
    }
    
    while (!temp.empty()) {
        cout << temp.top() << " ";
        temp.pop();
    }
    cout << endl;
}

// Main function
int main() {
    stack<int> s;

    // Pushing elements into the stack
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);

    cout << "Original Stack: ";
    printStack(s);

    int x = 5;  // Element to push at the bottom
    s = pushAtBottom(s, x);

    cout << "Stack after pushing " << x << " at bottom: ";
    printStack(s);

    return 0;
}
