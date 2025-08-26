class Solution {
public:
    int solve(int i, int j , vector<vector<int>>& obstacleGrid , vector<vector<int>> &dp)
    {
        // Out of bounds
        if(i < 0 || j < 0) return 0;

        // Obstacle
        if(obstacleGrid[i][j] == 1) return 0;

        // Reached start
        if(i == 0 && j == 0) return 1;

        if(dp[i][j] != -1)
        {
            return dp[i][j];
        }

        int up = solve(i-1 , j , obstacleGrid , dp);
        int left = solve(i , j-1 , obstacleGrid , dp);

        return dp[i][j] = up + left;
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        vector<vector<int>> dp(m ,vector<int>(n , -1));
        return solve(m-1 , n-1 , obstacleGrid , dp);
    }
};
