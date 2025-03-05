class Solution {
public:
    void backtrack(vector<int>& nums, int start, vector<int>& subset, vector<vector<int>>& result) {
        result.push_back(subset); // Add current subset to result
        
        for (int i = start; i < nums.size(); i++) {
            // Skip duplicates at the same level
            if (i > start && nums[i] == nums[i - 1]) continue;

            // Include current element
            subset.push_back(nums[i]);
            backtrack(nums, i + 1, subset, result);
            
            // Exclude current element (Backtrack)
            subset.pop_back();
        }
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> subset;
        
        // Sort to handle duplicates
        sort(nums.begin(), nums.end());
        
        // Start backtracking
        backtrack(nums, 0, subset, result);
        
        return result;
    }
};
