class Solution {
public:
    int countArr(vector<int>& nums, int sumArr)//pass no. of subarrays
    {
        int n=nums.size();
        int subArr=1;
        long long countSum=0;
        for(int i=0 ; i<n ; i++)
        {
            if(nums[i] + countSum <= sumArr)
            {
                countSum += nums[i];

            }
            else
            {
                subArr++;
                countSum = nums[i];
            }
        }
        return subArr;
    }

    int splitArray(vector<int>& nums, int k) 
    {
        int n=nums.size();
        int low = *max_element(nums.begin() , nums.end());
        int high =accumulate(nums.begin() , nums.end() , 0);

        if(k>n) return -1;

        while(low<=high)
        {
            int mid = low + (high - low)/2;
            if(countArr(nums , mid) > k)
            {
                low=mid+1;
            }
            else
            {
                high=mid-1;
            }
        }
        return low;
    }
};