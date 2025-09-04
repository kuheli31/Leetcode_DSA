class Solution {
public:
    int coinChange(vector<int>& coins, int amount) 
    {
        int n = coins.size();
        const int INF = 1e9;
        vector<int> prev(amount+1 , INF);

        // Base case: using only coin[0]
        for (int t = 0; t <= amount; t++) {
            if (t % coins[0] == 0) prev[t] = t / coins[0];
        }

        // Build DP table
        for (int ind = 1; ind < n; ind++) {
            for (int t = 0; t <= amount; t++) {
                int notTake = prev[t];
                int take = INF;
                if (coins[ind] <= t) {
                    take = 1 + prev[t - coins[ind]];
                }
                prev[t] = min(take, notTake);
            }
        }

        int ans = prev[amount];
        return (ans >= INF) ? -1 : ans;
    }
};
