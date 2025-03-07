class Solution {
public:
    set<vector<int>> resultSet;  // Stores unique subsets

    void backtrack(int index, vector<int>& nums, vector<int>& temp) 
    {
        resultSet.insert(temp);
        if (index >= nums.size()) return;

        temp.push_back(nums[index]);
        backtrack(index + 1, nums, temp);
        temp.pop_back(); // Backtrack step

        // Skip duplicate elements by advancing the index
        while (index + 1 < nums.size() && nums[index] == nums[index + 1]) index++;
        backtrack(index + 1, nums, temp);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end()); 
        vector<int> temp;
        backtrack(0, nums, temp);
        return vector<vector<int>>(resultSet.begin(), resultSet.end()); // Convert set to vector
    }
};