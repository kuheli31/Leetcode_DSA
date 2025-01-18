#include <bits/stdc++.h>
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int , int> mpp ;
        for(int i=0 ; i<nums.size() ; i++)
        {
            mpp[nums[i]]++;//counting number of times each number appears
        }
        for(auto it : mpp)//iterating through map
        {
            if(it.second > (nums.size()/2))// checking if count greater than n/2
            {
                return it.first;
            }
        }
        return -1;
    }
};