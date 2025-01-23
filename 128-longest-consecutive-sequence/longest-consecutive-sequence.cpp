class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int countCurrent=0 , lastSmaller=INT_MIN , longest=1;

        if(nums.size() == 0) return 0;

        sort(nums.begin() , nums.end());
        for(int i=0 ; i<nums.size() ;i++)
        {
            if(nums[i]-1 == lastSmaller)
            {
                countCurrent+=1;
                lastSmaller = nums[i];
            }
            else if(lastSmaller != nums[i])
            {
                countCurrent = 1;
                lastSmaller = nums[i];
            }

            longest=max(longest , countCurrent);
        }
        return longest;
    }
};