class Solution {
public:
    int f(int index , vector<int>& coins, int target, vector<vector<int>>& dp) {
        if (index == 0) {
            return (target % coins[0] == 0);
        }

        if (dp[index][target] != -1) return dp[index][target];

        int notTake = f(index-1 , coins , target, dp);
        int take = 0;
        if (coins[index] <= target) {
            take = f(index , coins , target - coins[index], dp);
        }

        return dp[index][target] = take + notTake;
    }

    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1, -1));
        return f(n-1 , coins , amount, dp);
    }
};
