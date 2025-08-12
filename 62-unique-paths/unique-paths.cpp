class Solution {
public:
    int solve(int m, int n)
    {
        vector<int> prev(n, 1); // First row initialized to 1

        for (int i = 1; i < m; i++) // Start from row 1
        {
            vector<int> curr(n, 1); // First column is always 1
            for (int j = 1; j < n; j++)
            {
                curr[j] = prev[j] + curr[j - 1];
            }
            prev = curr;
        }
        return prev[n - 1];
    }

    int uniquePaths(int m, int n)
    {
        return solve(m, n);
    }
};
