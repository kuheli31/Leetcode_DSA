class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
         // Step 1: Store the original indices
        vector<pair<int, int>> indexed_nums;
        for (int i = 0; i < nums.size(); i++) {
            indexed_nums.push_back({nums[i], i});
        }

        // Step 2: Sort the array based on values
        sort(indexed_nums.begin(), indexed_nums.end());

        // Step 3: Initialize two pointers
        int left = 0;
        int right = indexed_nums.size() - 1;

        // Step 4: Two-pointer logic
        while (left < right) {
            int sum = indexed_nums[left].first + indexed_nums[right].first;
            if (sum == target) {
                // Return the original indices
                return {indexed_nums[left].second, indexed_nums[right].second};
            } else if (sum < target) {
                left++;  // Move left pointer to the right
            } else {
                right--; // Move right pointer to the left
            }
        }

        return {}; // If no solution, return an empty vector
    }
};