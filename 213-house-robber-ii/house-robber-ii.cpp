class Solution {
public:
    int solve(int index , vector<int>& nums , vector<int> &dp)
    {
        dp[0] = nums[0];

        for(int i = 1; i <= index; i++)
        {
            int pick = nums[i];
            if(i > 1) pick += dp[i - 2];

            int notPick = dp[i - 1];
            dp[i] = max(pick , notPick);
        }
        return dp[index];
    }

    int rob(vector<int>& nums) 
    {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];

        // Case 1: Rob from 0 to n-2 (exclude last)
        vector<int> temp1(nums.begin(), nums.end() - 1);
        vector<int> dp1(n - 1, -1);
        int ans1 = solve(n - 2, temp1, dp1);

        // Case 2: Rob from 1 to n-1 (exclude first)
        vector<int> temp2(nums.begin() + 1, nums.end());
        vector<int> dp2(n - 1, -1);
        int ans2 = solve(n - 2, temp2, dp2);

        return max(ans1, ans2);
    }
};
