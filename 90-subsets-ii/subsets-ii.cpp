class Solution {
public:
    void backtrack(int index, vector<int>& nums, vector<int>& temp, vector<vector<int>>& result) {
        // Add the current subset to the result
        result.push_back(temp);

        // Explore further elements
        for (int i = index; i < nums.size(); i++) {
            // Skip duplicate elements
            if (i > index && nums[i] == nums[i - 1]) continue;

            // Pick the element
            temp.push_back(nums[i]);

            // Recur for the next index
            backtrack(i + 1, nums, temp, result);

            // Backtrack - remove the last added element
            temp.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> temp;
        
        // Step 1: Sort the array to handle duplicates
        sort(nums.begin(), nums.end());

        // Step 2: Start backtracking from index 0
        backtrack(0, nums, temp, result);

        return result;
     }
};
