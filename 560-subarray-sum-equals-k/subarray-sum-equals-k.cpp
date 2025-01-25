class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<long long , int> prefixMap;
        long long maxLength=0 , prefixSum=0; 
        long long i , remaining ,count=0;

        for(i=0 ; i<nums.size() ;i++)
        {
            prefixSum += nums[i];
            if(prefixSum == k)
            {
                count++;
            }
            remaining = prefixSum - k;
            if(prefixMap.find(remaining) != prefixMap.end())//element k found
            {
                 count += prefixMap[remaining];
            }

            prefixMap[prefixSum]++;
        }
        return count;
    }
};