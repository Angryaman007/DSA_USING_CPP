/*

Problem statement
You are given a 2D matrix ‘MATRIX’ of ‘N’*’M’ dimension. You have to return the spiral traversal of the matrix.

Example:

Input:
MATRIX = [ [1, 3, 5, 7], [10, 11, 16, 20], [23, 30, 34, 60] ]
Output:
1 3 5 7 20 60 34 30 23 10 11 16

Explanation: Starting from the element in the first row and the first column, traverse from left to right (1 3 5 7), then top to bottom (20 60), then right to left (34 30 23), then bottom to up (10) and then left to right (11 16).


*/

#include <iostream>
#include <vector>
using namespace std;

vector<int> spiralMatrix(vector<vector<int>>& matrix) {
    vector<int> ans;

    int row = matrix.size();
    if (row == 0) return ans;  // Handle edge case for empty matrix
    int col = matrix[0].size();  // Correct way to get the number of columns

    int count = 0;
    int total = row * col;

    // Index initialization
    int startingRow = 0;
    int startingCol = 0;
    int endingRow = row - 1;
    int endingCol = col - 1;

    // Use 'count < total' instead of 'cout < total'
    while (count < total) {
        // Traverse the starting row from left to right
        for (int index = startingCol; index <= endingCol && count < total; index++) {
            ans.push_back(matrix[startingRow][index]);
            count++;
        }
        startingRow++;

        // Traverse the ending column from top to bottom
        for (int index = startingRow; index <= endingRow && count < total; index++) {
            ans.push_back(matrix[index][endingCol]);
            count++;
        }
        endingCol--;

        // Traverse the ending row from right to left
        for (int index = endingCol; index >= startingCol && count < total; index--) {
            ans.push_back(matrix[endingRow][index]);
            count++;
        }
        endingRow--;

        // Traverse the starting column from bottom to top
        for (int index = endingRow; index >= startingRow && count < total; index--) {
            ans.push_back(matrix[index][startingCol]);
            count++;
        }
        startingCol++;
    }

    return ans;
}

int main() {
    // Sample Input 2: 4x4 matrix
    vector<vector<int>> matrix = {
        {1, 5, 9, 13},
        {14, 15, 16, 17},
        {19, 20, 21, 50},
        {59, 60, 71, 80}
    };

    vector<int> result = spiralMatrix(matrix);

    // Output the result in spiral order
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }

    return 0;
}
