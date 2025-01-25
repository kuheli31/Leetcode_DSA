class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map <int , int> mpp;
        int i , sum=0 , count=0;
        mpp[0]=1;
        for(i=0 ; i<nums.size() ; i++)
        {
            sum += nums[i];
            int remove = sum-k;
            count += mpp[remove];
            mpp[sum] += 1;
        }
        return count;
    }
};