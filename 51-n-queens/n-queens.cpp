class Solution {
public:
    void solve(int col , vector<string>&board , vector<vector<string>> &ans , vector<int>&leftRow , vector<int>&upperDiagonal , vector<int>&lowerDiagonal  , int n)
    {
       if(col == n)
        {
            ans.push_back(board);
            return;
        }
        else
        {
            for(int row = 0 ; row < n ; row++)
            {
               if(leftRow[row] == 0 && lowerDiagonal[row + col] == 0 && upperDiagonal[n - 1 + col - row] == 0)
               {
                    // Place the queen
                    board[row][col] = 'Q';
                    leftRow[row] = 1;
                    lowerDiagonal[row + col] = 1;
                    upperDiagonal[n - 1 + col - row] = 1;

                    // Recur for the next column
                    solve(col + 1 , board , ans , leftRow , upperDiagonal , lowerDiagonal , n);

                    // Backtrack: Remove the queen
                    board[row][col] = '.';
                    leftRow[row] = 0;
                    lowerDiagonal[row + col] = 0;
                    upperDiagonal[n - 1 + col - row] = 0;
               }
            }
        } 
    }

    vector<vector<string>> solveNQueens(int n) 
    {
        vector<vector<string>> ans;  // Stores all valid board configurations
        vector<string> board(n, string(n, '.'));  // Initializes the chessboard with '.'

        // Bitmask-style arrays for fast checking
        vector<int> leftRow(n, 0), upperDiagonal(2 * n - 1, 0), lowerDiagonal(2 * n - 1, 0);
        
        solve(0, board, ans, leftRow, upperDiagonal, lowerDiagonal, n);
        return ans;
    }
};
