class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini=prices[0];  // Initialize `mini` with the first price in the array. This represents the minimum price so far.
        int maxProfit=0;  // Initialize `maxProfit` to 0. This will store the maximum profit found.
        int i, n=prices.size();  // Declare the loop variable `i` and `n` for the number of prices in the array.

        // Loop through the entire `prices` array
        for(i=0; i<n; i++) {
            int cost = prices[i] - mini;  // Calculate the potential profit if we sell at the current price (`prices[i]`) after buying at the minimum price (`mini`).
            maxProfit = max(maxProfit, cost);  // Update the maximum profit if the calculated profit is greater than the current `maxProfit`.
            mini = min(mini, prices[i]);  // Update `mini` to ensure it holds the lowest price seen so far.
        }
        return maxProfit;  // Return the maximum profit obtained.
    }
};
