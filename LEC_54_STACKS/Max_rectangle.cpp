/*Max rectangle
Difficulty: HardAccuracy: 36.43%Submissions: 113K+Points: 8Average Time: 35m
Given a binary matrix mat[][] of size n * m. Find the maximum area of a rectangle formed only of 1s in the given matrix.

Examples:

Input: mat[][] = [[0, 1, 1, 0],
                [1, 1, 1, 1],
                [1, 1, 1, 1],
                [1, 1, 0, 0]]
Output: 8
Explanation: The largest rectangle with only 1’s is from (1, 0) to (2, 3) which is
[1, 1, 1, 1]
[1, 1, 1, 1]
and area is 4 *2 = 8.
Input: mat[][] = [[0, 1, 1],
                [1, 1, 1],
                [0, 1, 1]]
Output: 6
Explanation: The largest rectangle with only 1’s is from (0, 1) to (2, 2) which is
[1, 1]
[1, 1]
[1, 1]
Constraints:
1<= mat.size(), mat[0].size()<=1000
0<=mat[][]<=1
*/
#include <iostream>
using namespace std;

