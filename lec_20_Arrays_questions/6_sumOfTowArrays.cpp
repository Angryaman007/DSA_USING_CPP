/*

SUM OF TWO ARRAYS 

Problem statement
You are given two numbers 'A' and 'B' in the form of two arrays (A[] and B[]) of lengths 'N' and 'M' respectively, where each array element represents a digit. You need to find the sum of these two numbers and return this sum in the form of an array.

Note:

1. The length of each array is greater than zero.

2. The first index of each array is the most significant digit of the number. For example, if the array A[] = {4, 5, 1}, then the integer represented by this array is 451 and array B[] = {3, 4, 5} so the sum will be 451 + 345 = 796. So you need to return {7, 9, 6}.

3. Both numbers do not have any leading zeros in them. And subsequently, the sum should not contain any leading zeros.
Detailed explanation ( Input/output format, Notes, Images )
Constraints:
1 <= T <= 10^2
1 <= N, M <= 10^4
0 <= A[i], B[i] <= 9

Time Limit: 1 sec
Sample Input 1:
2
4 1 
1 2 3 4
6
3 2
1 2 3
9 9    
Sample Output 1:
1 2 4 0
2 2 2

*/
#include <bits/stdc++.h> 
using namespace std;

// Function to reverse a vector
vector<int> reverseVector(vector<int> v) {
    int s = 0;
    int e = v.size() - 1;
    while (s < e) {
        swap(v[s++], v[e--]);
    }
    return v;
}

// Function to find the sum of two arrays
vector<int> findArraySum(vector<int>& a, int n, vector<int>& b, int m) {
    int i = n - 1;
    int j = m - 1;
    vector<int> ans;
    int carry = 0;

    // Loop until both arrays are exhausted
    while (i >= 0 && j >= 0) {
        int val1 = a[i];
        int val2 = b[j];
        int sum = val1 + val2 + carry;
        carry = sum / 10;
        sum = sum % 10;
        ans.push_back(sum);
        i--;
        j--;
    }

    // If array a has remaining elements
    while (i >= 0) {
        int sum = a[i] + carry;
        carry = sum / 10;
        sum = sum % 10;
        ans.push_back(sum);
        i--;
    }

    // If array b has remaining elements
    while (j >= 0) {
        int sum = b[j] + carry;
        carry = sum / 10;
        sum = sum % 10;
        ans.push_back(sum);
        j--;
    }

    // If there's any carry left
    while (carry != 0) {
        int sum = carry;
        carry = sum / 10;
        sum = sum % 10;
        ans.push_back(sum);
    }

    // Reverse the result to get the correct order
    return reverseVector(ans);
}

// Main function to test the above logic
int main() {
    vector<int> a = {9, 9, 9};
    vector<int> b = {1};
    int n = a.size();
    int m = b.size();

    // Call the function to add the arrays
    vector<int> result = findArraySum(a, n, b, m);

    // Print the result
    for (int num : result) {
        cout << num << " ";
    }

    return 0;
}
