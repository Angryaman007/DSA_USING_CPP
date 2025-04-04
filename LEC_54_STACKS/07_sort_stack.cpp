/*
Problem statement
You’re given a stack consisting of 'N' integers. Your task is to sort this stack in descending order using recursion.

We can only use the following functions on this stack S.

is_empty(S) : Tests whether stack is empty or not.
push(S) : Adds a new element to the stack.
pop(S) : Removes top element from the stack.
top(S) : Returns value of the top element. Note that this function does not remove elements from the stack.
Note :
1) Use of any loop constructs like while, for..etc is not allowed.
2) The stack may contain duplicate integers.
3) The stack may contain any integer i.e it may either be negative, positive or zero.
Detailed explanation ( Input/output format, Notes, Images )
Constraints:
1 <= 'T' <= 100
1 <=  'N' <= 100
1 <= |'V'| <= 10^9

Where |V| denotes the absolute value of any stack element.

Time limit: 1 sec
Sample Input 1:
1
5
5 -2 9 -7 3
Sample Output 1:
9 5 3 -2 -7
Explanation of Sample Input 1:
9 Is the largest element, hence it’s present at the top. Similarly 5>3, 3>-2 and -7 being the smallest element is present at the last.
Sample Input 2:
1
5
-3 14 18 -5 30
Sample Output 2:
30 18 14 -3 -5
Explanation of Sample Input 2:
30 is the largest element, hence it’s present at the top. Similarly, 18>14, 14>-3 and -5 being the smallest element is present at the last.

*/

#include <iostream>
#include <stack>
using namespace std;

// fuction for sortedinseret

void sortedInsert(stack<int> &stack, int num)
{
	// base case
	if (stack.empty() || (!stack.empty() && stack.top() < num))
	{
		stack.push(num);
		return;
	}

	int n = stack.top();
	stack.pop();
	// recusive CAll
	sortedInsert(stack, num);
	stack.push(n);
}

void sortStack(stack<int> &stack)
{
	// Write your code here

	//base case 
	if(stack.empty())
	{
		return;
	}
	int num=stack.top();
stack.pop();

//recusive Call 
sortStack(stack);
sortedInsert(stack,num);
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

    // Pushing elements into the stack (unsorted)
    s.push(4);
    s.push(2);
    s.push(8);
    s.push(1);
    s.push(3);

    cout << "Original Stack: ";
    printStack(s);

    // Sort the stack
    sortStack(s);

    cout << "Sorted Stack: ";
    printStack(s);

    return 0;
}