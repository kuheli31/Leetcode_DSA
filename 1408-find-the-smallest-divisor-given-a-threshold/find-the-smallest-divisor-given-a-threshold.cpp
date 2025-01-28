class Solution {
public:
    int division(vector<int>& nums , int div)
    {
        long long divSum=0 , i;
        for(i=0 ; i<nums.size() ; i++)
        {
            divSum += ceil((double)nums[i] / div);
        }
        return divSum;
    }

    int smallestDivisor(vector<int>& nums, int threshold) 
    {
        long long low=1 , high = *max_element(nums.begin(), nums.end());;
        long long result=high;
        while(low <= high)
        {
            long long mid= low + (high - low)/2;
            if(division(nums , mid) <= threshold)
            {
                result = mid;
                high = mid -1;
            }
            else
            {
                low=mid+1;
            }
        }
        
        return result;
    }
};