class Solution {
public:
    int coinChange(vector<int>& coins, int amount) 
    {
        int n = coins.size();
        const int INF = 1e9;
        vector<vector<int>> dp(n, vector<int>(amount + 1, INF));

        // Base case: using only coin[0]
        for (int t = 0; t <= amount; t++) {
            if (t % coins[0] == 0) dp[0][t] = t / coins[0];
        }

        // Build DP table
        for (int ind = 1; ind < n; ind++) {
            for (int t = 0; t <= amount; t++) {
                int notTake = dp[ind-1][t];
                int take = INF;
                if (coins[ind] <= t) {
                    take = 1 + dp[ind][t - coins[ind]];
                }
                dp[ind][t] = min(take, notTake);
            }
        }

        int ans = dp[n-1][amount];

        if(ans >= INF)
        {
            return -1;
        }
        else
        {
            return ans;
        }
    }
};