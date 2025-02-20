class Solution {
public:
    vector<int> leftMax(vector<int>& height)
    {
        int n = height.size();
        vector<int> prefix(n);
        prefix[0] = height[0];
        for(int i = 1; i < n; i++)
        {
            prefix[i] = max(prefix[i - 1], height[i]);
        }
        return prefix;
    }

    vector<int> rightMax(vector<int>& height)
    {
        int n = height.size();
        vector<int> suffix(n);
        suffix[n - 1] = height[n - 1];
        for(int i = n - 2; i >= 0; i--)
        {
            suffix[i] = max(suffix[i + 1], height[i]);
        }
        return suffix;
    }

    int trap(vector<int>& height)
    {
        int n = height.size();
        vector<int> prefix = leftMax(height);
        vector<int> suffix = rightMax(height);
        int total = 0;
        for(int i = 0; i < n; i++)
        {
            int leftMax = prefix[i];
            int rightMax = suffix[i];
            if(height[i] < leftMax && height[i] < rightMax)
            {
                total += min(leftMax, rightMax) - height[i];
            }
        }
        return total;
    }
};
