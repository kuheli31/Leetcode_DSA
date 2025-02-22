class Solution {
public:
    long long subArrayRanges(vector<int>& nums) 
    {
        int i,j;
        int n=nums.size();
        long long sum=0;
        for(i=0 ; i<n ; i++)
        {
            int mini = nums[i];  // Track minimum element in current subarray
            int maxi = nums[i];  // Track maximum element in current subarray
            for(j=i ; j<n ; j++)
            {
                mini=min(mini,nums[j]);
                maxi=max(maxi,nums[j]);

                long long diff = maxi - mini;
                sum += diff;
            }
        }
        return sum;
    }
};