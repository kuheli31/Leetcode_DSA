class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini=prices[0];
        int maxProfit=0;
        int i,n=prices.size();

        for(i=0; i<n ;i++)
        {
            int cost= prices[i] - mini;
            maxProfit = max(maxProfit , cost);
            mini=min(mini ,prices[i]);
        }
        return maxProfit;
    }
};