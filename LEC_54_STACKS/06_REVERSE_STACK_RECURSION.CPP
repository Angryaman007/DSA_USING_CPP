/*
Problem statement
Reverse a given stack of 'N' integers using recursion. You are required to make changes in the input parameter itself.



Note: You are not allowed to use any extra space other than the internal stack space used due to recursion.



Example:
Input: [1,2,3,4,5] 
Output: [5,4,3,2,1]


*/

#include <iostream>
#include <stack>
using namespace std;

//fuction for instertATBottom 
void insertAtBottom(stack<int> &s , int element )
{
//base case 
if(s.empty()){
    s.push(element);
    return;
}
int num =s.top();
s.pop();

//recursive call 
insertAtBottom(s,element);
s.push(num);
}

void reverseStack(stack<int> &stack) {
    // Write your code here
    //BASE CASE FOR RECUSRION TO USE 
    if(stack.empty()){
        return ;
    }

// to take out  first element 
    int num =stack.top();
    stack.pop();

    //Recursive Call 
    reverseStack(stack);

    insertAtBottom(stack,num);
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

    // Reverse the stack
    reverseStack(s);

    cout << "Reversed Stack: ";
    printStack(s);

    return 0;
}
