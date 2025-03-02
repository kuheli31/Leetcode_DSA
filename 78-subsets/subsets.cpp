class Solution {
public:
    void subsequence(int index, vector<int> &nums, vector<int> &current, vector<vector<int>> &result) {
        int n = nums.size();
        if (index >= n) {
            result.push_back(current);  // Store the current subset
            return;
        }
        // Include the current element
        current.push_back(nums[index]);
        subsequence(index + 1, nums, current, result);
        
        // Exclude the current element
        current.pop_back();
        subsequence(index + 1, nums, current, result);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> current;
        vector<vector<int>> result;
        subsequence(0, nums, current, result);
        return result;  // Return all subsets
    }
};