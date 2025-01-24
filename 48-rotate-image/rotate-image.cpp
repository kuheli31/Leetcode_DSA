class Solution {
public:
    void rotate(vector<vector<int>>& matrix) 
    {
        int n = matrix.size(); // Correct size of the matrix
        vector<vector<int>> ans(n, vector<int>(n)); // Create a temporary matrix for the result
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                ans[j][n - 1 - i] = matrix[i][j]; // Rotate 90 degrees clockwise
            }
        }
        
        // Copy the result back into the original matrix
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                matrix[i][j] = ans[i][j];
            }
        }
    }
};
