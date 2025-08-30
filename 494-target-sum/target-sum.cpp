class Solution {
public:
    int solve(int i , vector<int>& nums, int target) 
    {
        // base case: processed all numbers
        if (i < 0) {
            if (target == 0) {
                return 1;
            } else {
                return 0;
            }
        }

        // choice 1: put '+' before nums[i]
        int plus = solve(i - 1, nums, target - nums[i]);

        // choice 2: put '-' before nums[i]
        int minus = solve(i - 1, nums, target + nums[i]);

        return plus + minus;
    }

    int findTargetSumWays(vector<int>& nums, int target) 
    {
        int n = nums.size();
        return solve(n - 1 , nums , target);
    }
};
