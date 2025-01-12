class Solution {
public:
    int removeDuplicates(vector<int>& nums) 
    {
        int i,count=0;
        for(i=1;i<nums.size();i++)
        {
            if(nums[i]!=nums[count])
            {
                count++;
                nums[count]=nums[i];
            }
        }
        return count+1;
    }
};