class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) 
    {
        int n1=nums1.size();
        int n2=nums2.size();

        vector<int> result(n1);
        for(int i=0 ; i<n1 ; i++)
        {
            bool found=false;// to find element of nums1 in nums2
            for(int j=0 ; j<n2 ; j++)
            {
                if(nums1[i] == nums2[j])
                {
                    found=true;
                }
                if(found && nums2[j]>nums1[i])
                {
                    result[i]=nums2[j];
                    break;
                }
            }
        }
        for(int i=0 ; i<result.size() ; i++)
        {
            if(result[i] == 0)
            {
                result[i]=-1;
            }
        }
        return result;
    }
};