

/*

Consider a rat placed at position (0, 0) in an n x n square matrix mat. The rat's goal is to reach the destination at position (n-1, n-1). The rat can move in four possible directions: 'U'(up), 'D'(down), 'L' (left), 'R' (right).

The matrix contains only two possible values:

0: A blocked cell through which the rat cannot travel.
1: A free cell that the rat can pass through.
Note: In a path, no cell can be visited more than one time. If the source cell is 0, the rat cannot move to any other cell. In case of no path, return an empty list.+

The task is to find all possible paths the rat can take to reach the destination, starting from (0, 0) and ending at (n-1, n-1), under the condition that the rat cannot revisit any cell along the same path. Furthermore, the rat can only move to adjacent cells that are within the bounds of the matrix and not blocked.

Examples:

Input: mat[][] = [[1, 0, 0, 0], [1, 1, 0, 1], [1, 1, 0, 0], [0, 1, 1, 1]]
Output: ["DDRDRR", "DRDDRR"]
Explanation: The rat can reach the destination at (3, 3) from (0, 0) by two paths - DRDDRR and DDRDRR, when printed in sorted order we get DDRDRR DRDDRR.
Input: mat[][] = [[1, 0], [1, 0]]
Output: []
Explanation: No path exists and the destination cell is blocked.
Input: mat = [[1, 1, 1], [1, 0, 1], [1, 1, 1]]
Output: ["DDRR", "RRDD"]
Explanation: The rat has two possible paths to reach the destination: 1. "DDRR" 2. "RRDD", These are returned in lexicographically sorted order.

*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
    // Helper function to check if the move is safe
    bool isSafe(int x, int y, int n, vector<vector<int>> &visited, vector<vector<int>> &m) {
        return (x >= 0 && x < n && y >= 0 && y < n && visited[x][y] == 0 && m[x][y] == 1);
    }

    // Recursive function to find all paths
    void solve(vector<vector<int>> &m, int n, vector<string> &ans, int x, int y, vector<vector<int>> &visited, string path) {
        // Base case: if the destination is reached, store the path and return
        if (x == n - 1 && y == n - 1) {
            ans.push_back(path);
            return;
        }

        // Mark the current cell as visited
        visited[x][y] = 1;

        // Explore all four possible directions: Down, Left, Right, Up
        // Down
        int newx = x + 1;
        int newy = y;
        if (isSafe(newx, newy, n, visited, m)) {
            path.push_back('D');
            solve(m, n, ans, newx, newy, visited, path);
            path.pop_back(); // Backtrack
        }

        // Left
        newx = x;
        newy = y - 1;
        if (isSafe(newx, newy, n, visited, m)) {
            path.push_back('L');
            solve(m, n, ans, newx, newy, visited, path);
            path.pop_back(); // Backtrack
        }

        // Right
        newx = x;
        newy = y + 1;
        if (isSafe(newx, newy, n, visited, m)) {
            path.push_back('R');
            solve(m, n, ans, newx, newy, visited, path);
            path.pop_back(); // Backtrack
        }

        // Up
        newx = x - 1;
        newy = y;
        if (isSafe(newx, newy, n, visited, m)) {
            path.push_back('U');
            solve(m, n, ans, newx, newy, visited, path);
            path.pop_back(); // Backtrack
        }

        // Unmark the current cell (backtracking)
        visited[x][y] = 0;
    }

public:
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string> ans;

        // Edge case: if the start or destination cell is blocked
        if (n == 0 || m[0][0] == 0 || m[n - 1][n - 1] == 0) {
            return ans;
        }

        // Initialize visited matrix with 0
        vector<vector<int>> visited(n, vector<int>(n, 0));

        // Start recursive function from (0, 0)
        string path = "";
        solve(m, n, ans, 0, 0, visited, path);

        // Sort the paths lexicographically
        sort(ans.begin(), ans.end());
        return ans;
    }
};

// Test the solution
int main() {
    Solution sol;
    vector<vector<int>> mat = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {1, 1, 0, 0},
        {0, 1, 1, 1}
    };
    int n = mat.size();
    vector<string> result = sol.findPath(mat, n);

    // Print the result
    if (result.empty()) {
        cout << "No paths found." << endl;
    } else {
        for (const string &path : result) {
            cout << path << " ";
        }
        cout << endl;
    }

    return 0;
}
