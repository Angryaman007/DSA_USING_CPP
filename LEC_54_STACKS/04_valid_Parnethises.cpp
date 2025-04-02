 /*
 Problem statement
You're given a string 'S' consisting of "{", "}", "(", ")", "[" and "]" .



Return true if the given string 'S' is balanced, else return false.



For example:
'S' = "{}()".

There is always an opening brace before a closing brace i.e. '{' before '}', '(' before ').
So the 'S' is Balanced.
Detailed explanation ( Input/output format, Notes, Images )
Sample Input 1 :
[()]{}{[()()]()}
Sample Output 1 :
Balanced
Explanation Of the Sample Input 1 :
There is always an opening brace before a closing brace i.e. '{' before '}', '(' before '), '[' before ']'.
So the 'S' is Balanced.
Sample Input 2 :
[[}[
Sample Output 2 :
Not Balanced
Constraints:
1 <= 'N' <= 10^5

Where 'N' is the length of the input string 'S'.
Time Limit: 1 sec

*/

#include <iostream>
#include <stack>
using namespace std;

bool isValidParenthesis(string s) {
    stack<char> st; // Renamed the stack variable to avoid shadowing
    
    for (int i = 0; i < s.length(); i++) {
        char ch = s[i];

        // If it's an opening bracket, push to stack
        if (ch == '(' || ch == '{' || ch == '[') {
            st.push(ch);
        } else {
            // If it's a closing bracket, check the top of the stack
            if (!st.empty()) {
                char top = st.top();
                if ((ch == ')' && top == '(') || 
                    (ch == '}' && top == '{') || 
                    (ch == ']' && top == '[')) {
                    st.pop();
                } else {
                    return false; // Mismatched closing bracket
                }
            } else {
                return false; // Stack is empty but found a closing bracket
            }
        }
    }

    return st.empty(); // If stack is empty, parentheses are balanced
}

// Main function for testing
int main() {
    string test1 = "(){}[]"; 
    string test2 = "({[)]}"; 
    string test3 = "({[]})"; 
    
    cout << "Test 1: " << (isValidParenthesis(test1) ? "Valid" : "Invalid") << endl;
    cout << "Test 2: " << (isValidParenthesis(test2) ? "Valid" : "Invalid") << endl;
    cout << "Test 3: " << (isValidParenthesis(test3) ? "Valid" : "Invalid") << endl;

    return 0;
}
