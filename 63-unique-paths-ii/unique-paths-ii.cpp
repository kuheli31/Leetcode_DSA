class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        vector<int> dp(n, 0);

        for(int i = 0; i < m; i++) {
            vector<int> temp(n, 0); // current row
            for(int j = 0; j < n; j++) {
                if(obstacleGrid[i][j] == 1) {
                    temp[j] = 0; // obstacle → no path
                }
                else if(i == 0 && j == 0) {
                    temp[j] = 1; // starting point
                }
                else {
                    int up = (i > 0) ? dp[j] : 0;
                    int left = (j > 0) ? temp[j-1] : 0;
                    temp[j] = up + left;
                }
            }
            dp = temp; // move to next row
        }

        return dp[n-1];
    }
};
