class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        // dp table: same size as matrix
        vector<vector<int>> dp(n, vector<int>(m, 0));

        // Base case: first row is same as matrix
        for (int j = 0; j < m; j++) {
            dp[0][j] = matrix[0][j];
        }

        // Fill dp row by row
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int up = dp[i-1][j];
                int upLeft = (j > 0) ? dp[i-1][j-1] : INT_MAX;
                int upRight = (j < m-1) ? dp[i-1][j+1] : INT_MAX;

                dp[i][j] = matrix[i][j] + min({up, upLeft, upRight});
            }
        }

        // Answer = minimum in last row
        int ans = INT_MAX;
        for (int j = 0; j < m; j++) {
            ans = min(ans, dp[n-1][j]);
        }

        return ans;
    }
};
