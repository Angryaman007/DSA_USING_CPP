/*

ARRAY IS SORTED AND ROTEDED 

Given an array nums, return true if the array was originally sorted in non-decreasing order, then rotated some number of positions (including zero). Otherwise, return false.

There may be duplicates in the original array.

Note: An array A rotated by x positions results in an array B of the same length such that A[i] == B[(i+x) % A.length], where % is the modulo operation.

 

Example 1:

Input: nums = [3,4,5,1,2]
Output: true
Explanation: [1,2,3,4,5] is the original sorted array.
You can rotate the array by x = 3 positions to begin on the the element of value 3: [3,4,5,1,2].

*/

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std; 


class Solution {
public:
    bool check(vector<int>& nums) {
        
        int count=0;
        int n=nums.size();

        for( int i=1; i<n; i++)
        {
            if(nums[i-1]>nums[i])
            {
                count++;
            }
        }
        if(nums[n-1]>nums[0])
        count++;
        return count<=1;
    }
};

int main()
{

 vector<int>nums={3,4,5,1,2};

 Solution sol;

 if (sol.check(nums)) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }

    return 0;

}