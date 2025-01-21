class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) 
    {
        vector<int> positive;
        vector<int> negative;
        vector<int> result; // Resultant vector to store rearranged elements
        int i;

        // Separate positive and negative numbers into two vectors
        for(i = 0; i < nums.size(); i++)
        {
            if(nums[i] > 0)
            {
                positive.push_back(nums[i]);
            }
            else
            {
                negative.push_back(nums[i]);
            }
        }

        // Merge the positive and negative numbers alternatively
        for(i = 0; i < positive.size(); i++)
        {
            result.push_back(positive[i]);
            result.push_back(negative[i]);
        }

        return result; // Return the rearranged array
    }
};