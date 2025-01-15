#include <iostream>
#include <vector>
using namespace std;

class Solution
{
private:
    void solve(vector<int> nums, vector<int> output, int index, vector<vector<int>> &ans)
    {
        // base case
        if (index >= nums.size())
        {
            ans.push_back(output);
            return;
        }

        // exclude
        solve(nums, output, index + 1, ans);

        // include
        int element = nums[index];
        output.push_back(element);
        solve(nums, output, index + 1, ans);
    }

public:
    vector<vector<int>> subsets(vector<int> &nums)
    {

        vector<vector<int>> ans;
        vector<int> output;
        int index = 0;
        solve(nums, output, index, ans);

        return ans;
    }
};

int main()
{
    // Input array size
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    // Input the elements of the array
    vector<int> nums(n);
    cout << "Enter the elements: ";
    for (int i = 0; i < n; ++i)
    {
        cin >> nums[i];
    }

    // Create Solution object and call the subsets function
    Solution solution;
    vector<vector<int>> result = solution.subsets(nums);

    // Output the result (subsets)
    cout << "Subsets are: \n";
    for (const auto &subset : result)
    {
        cout << "[";
        for (int i = 0; i < subset.size(); ++i)
        {
            cout << subset[i];
            if (i != subset.size() - 1)
                cout << ", ";
        }
        cout << "]\n";
    }
    return 0;
}