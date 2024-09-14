/*

MOVE ZEOES

Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.

Note that you must do this in-place without making a copy of the array.

 

Example 1:

Input: nums = [0,1,0,3,12]
Output: [1,3,12,0,0]
Example 2:

Input: nums = [0]
Output: [0]
*/
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:

void moveZeroes(std::vector<int>& nums) {
    int i=0;
        for (int j = 0; j < nums.size(); j++) {
            if (nums[j] != 0) {
                std::swap(nums[j], nums[i]);
                i++;
            }
        }
    }
};

int main()
{

    std::vector<int>nums={0,1,0,3,12};

    Solution sol;
    sol.moveZeroes(nums);

     std::cout << "Output for Example 1: ";
    for (int num : nums) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

   return 0; 

}
