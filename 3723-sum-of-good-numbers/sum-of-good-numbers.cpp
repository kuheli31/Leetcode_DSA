class Solution {
public:
    int checkMin(vector<int>& nums, int k ,int i)
    {
        int n=nums.size();
        int p1=i-k;
        int p2=i+k;

        if (p1 >= 0 && p1 < n) {  
        if (p2 >= 0 && p2 < n) {  
            return min(p1, p2);  // Both are valid, return the smaller one
        }
        return p1;  // Only p1 is valid
    } 
    return p2;  // If p1 is invalid, return p2
    }
    int sumOfGoodNumbers(vector<int>& nums, int k) 
    {
        int n=nums.size();
        int sum=0;
        
        for(int i=0 ; i<n ; i++)
        {
        int p1=i-k;
        int p2=i+k;
            int minIndex = checkMin(nums, k, i);
            if(minIndex >= 0 && minIndex < n && nums[i] > nums[minIndex])
            {
                if ((p1 < 0 || nums[i] > nums[p1]) && 
                    (p2 >= n || nums[i] > nums[p2])) 
                {
                    sum += nums[i];
                }
            }
        }
        return sum;
    }
};