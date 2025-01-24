class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) 
    {
        int n=matrix.size();
        int m=matrix[0].size();
        int i;
        int left=0 , right=m-1;
        int top=0 , bottom=n-1;
        vector<int> ans;

        while(top<=bottom && left<=right)
        {
        //left - right
        for(i=left ; i<=right ;i++)
        {
            ans.push_back(matrix[top][i]);
        }
        top++;

        //top - bottom
        for(i=top ; i<=bottom ;i++)
        {
            ans.push_back(matrix[i][right]);
        }
        right--;

        //right - left
        if(top <= bottom)
        {
            for(i=right ; i>=left ; i--)
            {
                ans.push_back(matrix[bottom][i]);
            }
        bottom--;
        }

        //bottom - top
        if(left <= right)
        {
            for(i=bottom ; i>=top ;i--)
            {
                ans.push_back(matrix[i][left]);
            }
            left++;
        }
        }

        return ans;
    }
};