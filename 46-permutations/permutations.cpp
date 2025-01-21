class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        static vector<int> arr;             // To track used elements
        static vector<int> result;          // Current permutation
        static vector<vector<int>> finalResult; // To store all permutations
        
        // Reinitialize static variables at the beginning of each test case
        if (arr.empty() && result.empty() && finalResult.empty()) {
            arr.resize(nums.size(), 0);
        }

        int k = result.size(); // k is the current depth of the recursion

        if (k == nums.size()) { // Base case: permutation is complete
            finalResult.push_back(result); // Add current permutation to finalResult
            return finalResult;
        } else {
            for (int i = 0; i < nums.size(); i++) {
                if (arr[i] == 0) { // If the number is not used
                    result.push_back(nums[i]); // Add to current permutation
                    arr[i] = 1;                // Mark as used
                    permute(nums);             // Recursive call
                    result.pop_back();         // Backtrack
                    arr[i] = 0;                // Mark as unused
                }
            }
        }

        if (result.empty() && k == 0) { // Clear static variables after processing
            vector<vector<int>> output = finalResult;
            finalResult.clear();
            arr.clear();
            return output;
        }

        return finalResult; // Return all permutations
    }
};
