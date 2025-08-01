class Solution {
public:
    int solve(int index , vector<int>& nums , vector<int> &dp)
    {
        dp[0] = nums[0];

        for(int i=1 ; i<=index ; i++)
        {
            int pick = nums[i];
            if(i > 1) pick += dp[i-2];

            int notPick = dp[i-1];
            dp[i] = max(pick , notPick);
        }
        return dp[index];
    }

    int rob(vector<int>& nums) 
    {
        int n = nums.size();
        vector<int> dp(n , -1);
        return solve(n-1 , nums , dp);
    }
};