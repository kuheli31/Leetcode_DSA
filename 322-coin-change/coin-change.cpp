class Solution {
public:
    int coinChange(vector<int>& coins, int amount) 
    {
        int n = coins.size();
        const int INF = 1e9;
        vector<int> prev(amount+1 , 0);
        vector<int> curr(amount+1 , 0);
        // Base case: using only coin[0]
        for (int t = 0; t <= amount; t++) {
            if (t % coins[0] == 0) prev[t] = t / coins[0];
            else prev[t] = INF;
        }

        // Build DP table
        for (int ind = 1; ind < n; ind++) {
            for (int t = 0; t <= amount; t++) {
                int notTake = prev[t];
                int take = INF;
                if (coins[ind] <= t) {
                    take = 1 + curr[t - coins[ind]];
                }
                curr[t] = min(take, notTake);
            }
            prev = curr;
            fill(curr.begin(), curr.end(), 0);
        }

        int ans = prev[amount];

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