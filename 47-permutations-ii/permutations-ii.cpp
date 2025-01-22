class Solution {
public:
    vector<vector<int>> result; // To store all unique permutations
    vector<bool> used;          // To track whether an element is used in the current permutation

    void backtrack(vector<int>& nums, vector<int>& current) {
        if (current.size() == nums.size()) {
            // Base case: When the current permutation is complete
            result.push_back(current);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            // Skip already used elements or skip duplicates (nums[i] == nums[i-1]) in the same recursion level
            if (used[i] || (i > 0 && nums[i] == nums[i - 1] && !used[i - 1]))
                continue;

            // Mark the current element as used
            used[i] = true;
            current.push_back(nums[i]); // Add current element to the current permutation

            // Recursively generate permutations
            backtrack(nums, current);

            // Backtrack by removing the current element and marking it as unused
            current.pop_back();
            used[i] = false;
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end()); // Sort to handle duplicates
        used.resize(nums.size(), false); // Initialize the used vector
        vector<int> current;             // Current permutation being built
        backtrack(nums, current);        // Start backtracking
        return result;
    }
};