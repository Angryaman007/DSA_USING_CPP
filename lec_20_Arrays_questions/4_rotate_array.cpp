/*

ROTATE ARRAY

Given an integer array nums, rotate the array to the right by k steps, where k is non-negative.

 

Example 1:

Input: nums = [1,2,3,4,5,6,7], k = 3
Output: [5,6,7,1,2,3,4]
Explanation:
rotate 1 steps to the right: [7,1,2,3,4,5,6]
rotate 2 steps to the right: [6,7,1,2,3,4,5]
rotate 3 steps to the right: [5,6,7,1,2,3,4]

*/
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
       vector<int>temp(nums.size());
       for(int i=0; i<nums.size(); i++){
        temp[(i+k)%nums.size()]=nums[i];
       } 

       //copy temp into num vector 

       nums=temp;

    }
};
int main()
{
    vector<int> nums={1,2,3,4,5,6,7};
    int k;

    Solution sol;

    sol.rotate(nums,3);
    std::cout << "Output for Example 1: ";
    for (int num : nums) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

   return 0; 


}