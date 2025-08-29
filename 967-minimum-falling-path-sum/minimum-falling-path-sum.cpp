class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        // Only keep one row for previous
        vector<int> prev(m, 0), curr(m, 0);

        // Base case: first row
        for (int j = 0; j < m; j++) {
            prev[j] = matrix[0][j];
        }

        // Fill row by row
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int up = prev[j];
                int upLeft = (j > 0) ? prev[j-1] : INT_MAX;
                int upRight = (j < m-1) ? prev[j+1] : INT_MAX;

                curr[j] = matrix[i][j] + min({up, upLeft, upRight});
            }
            prev = curr;  // move current row to previous
        }

        // Answer = minimum in the last row
        return *min_element(prev.begin(), prev.end());
    }
};
