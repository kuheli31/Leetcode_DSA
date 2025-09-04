class Solution {
public:
    int coinChange(vector<int>& coins, int amount) 
    {
        int n = coins.size();
        const int INF = 1e9;
        vector<int> dp(amount + 1, INF);

        // Base case
        dp[0] = 0;

        // For each coin, update dp[]
        for (int ind = 0; ind < n; ind++) {
            for (int t = coins[ind]; t <= amount; t++) {
                dp[t] = min(dp[t], 1 + dp[t - coins[ind]]);
            }
        }

        int ans = dp[amount];
        return (ans >= INF) ? -1 : ans;
    }
};
