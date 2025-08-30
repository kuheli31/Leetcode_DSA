class Solution {
public:
    int solve(int i , int j1 , int j2 , vector<vector<int>>& grid , vector<vector<vector<int>>> &dp)
    {
        int r , c;
        r = grid.size();
        c = grid[0].size();

        //Out of Bound
        if(j1<0 || j2<0 || j1>=c || j2>=c)
        {
            return -1e9;
        }
        //Possible ans
        if(i == r-1)
        {
            if(j1 == j2) return grid[i][j1];
            else return grid[i][j1] + grid[i][j2];
        }

        if(dp[i][j1][j2] != -1)
        {
            return dp[i][j1][j2];
        }

        //Explore all the paths
        int maxi = -1e9;
        for(int dj1=-1 ; dj1<=+1 ; dj1++)
        {
            for(int dj2=-1 ; dj2<=+1 ; dj2++)
            {
                int value=0;
                if(j1 == j2) 
                {
                    value = grid[i][j1];
                } 
                else 
                {
                    value += grid[i][j1] + grid[i][j2] + solve(i+1 , j1+dj1 , j2+dj2 , grid , dp);
                }
                maxi = max(maxi , value);
            }
        }
        return dp[i][j1][j2] = maxi;
    }

    int cherryPickup(vector<vector<int>>& grid) {
        int m , n;
        m = grid.size();
        n = grid[0].size();
        //dp[r][c][c]
        vector<vector<vector<int>>> dp(m , vector<vector<int>>(n , vector<int>(n , -1)));
        return solve(0, 0, n-1, grid , dp);
    }
};