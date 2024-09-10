/*Problem statement
You are given an array 'arr' consisting of 'n' integers which denote the position of a stall.



You are also given an integer 'k' which denotes the number of aggressive cows.



You are given the task of assigning stalls to 'k' cows such that the minimum distance between any two of them is the maximum possible.



Print the maximum possible minimum distance.



Example:
Input: 'n' = 3, 'k' = 2 and 'arr' = {1, 2, 3}

Output: 2

Explanation: The maximum possible minimum distance will be 2 when 2 cows are placed at positions {1, 3}. Here distance between cows is 2.

*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isPossible(vector<int> &stalls, int k, int mid) {
    int cowCount = 1;  // Place the first cow
    int lastPos = stalls[0];  // First cow is placed at the first stall

    for (int i = 1; i < stalls.size(); i++) {  // Start checking from the second stall
        if (stalls[i] - lastPos >= mid) {  // Check if we can place the next cow here
            cowCount++;
            if (cowCount == k) {  // All cows are placed successfully
                return true;
            }
            lastPos = stalls[i];  // Update the last position where a cow was placed
        }
    }
    return false;
}

int aggressiveCows(vector<int> &stalls, int k) {
    // Sort the stalls
    sort(stalls.begin(), stalls.end());

    // Binary search range: min distance = 0, max distance = last - first stall
    int s = 0;
    int e = stalls[stalls.size() - 1] - stalls[0];
    int ans = -1;
    int mid = s + (e - s) / 2;

    // Perform binary search to find the largest minimum distance
    while (s <= e) {
        if (isPossible(stalls, k, mid)) {
            ans = mid;  // mid is a valid distance, try to find a larger one
            s = mid + 1;
        } else {
            e = mid - 1;  // mid is not a valid distance, reduce the range
        }
        mid = s + (e - s) / 2;
    }

    return ans;
}

int main() {
    vector<int> stalls = {1, 2, 8, 4, 9};  // Stall positions
    int k = 3;  // Number of cows

    cout << "Largest minimum distance: " << aggressiveCows(stalls, k) << endl;
    return 0;
}
