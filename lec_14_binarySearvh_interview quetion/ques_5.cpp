/*

Problem statement

 Given an array/list of length ‘n’, where the array/list represents the boards and each element of the given array/list represents the length of each board. Some ‘k’ numbers of painters are available to paint these boards. Consider that each unit of a board takes 1 unit of time to paint.



 You are supposed to return the area of the minimum time to get this job done of painting all the ‘n’ boards under a constraint that any painter will only paint the continuous sections of boards.



 Example :
 Input: arr = [2, 1, 5, 6, 2, 3], k = 2

 Output: 11

 Explanation:

 First painter can paint boards 1 to 3 in 8 units of time and the second painter can paint boards 4-6 in 11 units of time. Thus both painters will paint all the boards in max(8,11) = 11 units of time. It can be shown that all the boards can't be painted in less than 11 units of time.

*/

#include <iostream>
#include <vector>
using namespace std;

// Function to check if it is possible to paint all boards with 'k' painters in 'maxTime' time.
bool isPossible(vector<int>& boards, int n, int k, int mid) {
    int painterCount = 1;
    int boardSum = 0;

    for (int i = 0; i < n; i++) {
        if (boardSum + boards[i] <= mid) {
            boardSum += boards[i];
        } else {
            painterCount++;
            if (painterCount > k || boards[i] > mid) {
                return false;
            }
            boardSum = boards[i];
        }
    }
    return true;
}

#include <iostream>
#include <vector>
#include <numeric>  // For accumulate
using namespace std;

// Function to find the maximum element in a vector.
int findMax(const vector<int>& boards) {
    int maxVal = boards[0];
    for (int i = 1; i < boards.size(); i++) {
        if (boards[i] > maxVal) {
            maxVal = boards[i];
        }
    }
    return maxVal;
}

// Function to check if it is possible to paint all boards with 'k' painters in 'maxTime' time.
bool isPossible(const vector<int>& boards, int n, int k, int mid) {
    int painterCount = 1;
    int boardSum = 0;

    for (int i = 0; i < n; i++) {
        if (boardSum + boards[i] <= mid) {
            boardSum += boards[i];
        } else {
            painterCount++;
            if (painterCount > k || boards[i] > mid) {
                return false;
            }
            boardSum = boards[i];
        }
    }
    return true;
}

// Function to find the minimum time required to paint all boards.
int findMinTime(const vector<int>& boards, int n, int k) {
    // Early check if there are more painters than boards.
    if (k > n) {
        return -1;
    }

    int low = findMax(boards);  // Minimum time is the largest board
    int high = accumulate(boards.begin(), boards.end(), 0);  // Maximum time is the sum of all boards
    int result = high;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (isPossible(boards, n, k, mid)) {
            result = mid;  // Mid is a valid solution, try to find a smaller one
            high = mid - 1;
        } else {
            low = mid + 1;  // Mid is not a valid solution, increase the time
        }
    }
    return result;
}

int main() {
    vector<int> boards = {2, 1, 5, 6, 2, 3};  // Lengths of the boards
    int k = 2;  // Number of painters

    // Output the minimum time to paint all the boards
    cout << findMinTime(boards, boards.size(), k) << endl;  // Expected output: 11

    return 0;
}

