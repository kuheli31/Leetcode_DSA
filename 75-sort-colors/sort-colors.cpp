class Solution {
public:

    void quicksort(vector<int>& nums , int low ,int high)
    {
        if(low < high)
        {
        int pindex = partition(nums , low , high);
        quicksort(nums , low , pindex -1);
        quicksort(nums , pindex+1 , high);
        }
    }

    int partition(vector<int>& nums , int low ,int high)
    {
        int pivot= nums[low];
        int i=low;
        int j=high;

        while(i<j)
        {
            while(nums[i]<=pivot && i<high)
            {
                i++;
            }
            while(nums[j]>pivot && j>low)
            {
                j--;
            }
            if(i<j)
            {
                swap(nums[i] , nums[j]);
            }
        }
        swap(nums[low],nums[j]);
        return j;
    }

    void sortColors(vector<int>& nums) 
    {
        return (quicksort(nums , 0 , nums.size()-1));
    }
};