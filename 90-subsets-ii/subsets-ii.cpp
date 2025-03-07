#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void backtrack(int index, vector<int>& nums, vector<int>& temp, set<vector<int>>& result) {
        // Insert the current subset into the set (ensures uniqueness)
        result.insert(temp);

        // Explore further elements
        for (int i = index; i < nums.size(); i++) {
            // Pick the element
            temp.push_back(nums[i]);

            // Recur for the next index
            backtrack(i + 1, nums, temp, result);

            // Backtrack - remove the last added element
            temp.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>> resultSet;  // Set to store unique subsets
        vector<int> temp;

        // Step 1: Sort the array to handle duplicates
        sort(nums.begin(), nums.end());

        // Step 2: Start backtracking from index 0
        backtrack(0, nums, temp, resultSet);

        // Convert set to vector of vectors
        return vector<vector<int>>(resultSet.begin(), resultSet.end());
    }
};