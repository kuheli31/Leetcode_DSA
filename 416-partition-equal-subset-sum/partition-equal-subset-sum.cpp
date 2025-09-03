class Solution {
public:
    bool f(int ind, int target, vector<int>& nums, vector<vector<int>>& dp) {
        if (target == 0) {
            return true;
        }
        if (ind == 0) {
            return (nums[0] == target);
        }
        if (dp[ind][target] != -1) {
            return dp[ind][target];
        }

        bool notTake = f(ind - 1, target, nums, dp);
        bool take = false;
        if (nums[ind] <= target) {
            take = f(ind - 1, target - nums[ind], nums, dp);
        }

        return dp[ind][target] = notTake || take;
    }

    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (int n : nums) {
            sum += n;
        }

        int target;
        if (sum % 2 != 0) {
            return false;
        } else {
            target = sum / 2;
        }
        int s = nums.size();
        vector<vector<int>> dp(s , vector<int>(target+1 , -1));
        return f(s - 1, target, nums , dp);
    }
};