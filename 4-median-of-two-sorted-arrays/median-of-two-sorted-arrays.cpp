class Solution {
public:
    double medianValue(vector<int>& newVec,int n)
    {
        if (n % 2 == 1) 
        {
            return newVec[n / 2] ; // Middle index for odd length
        } else 
        {
            return (newVec[n / 2 - 1] + newVec[n / 2]) / 2.0;
        }
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
    {
        vector<int> newVec;
        float medi=0;
        newVec.insert(newVec.end(), nums1.begin(), nums1.end());
        newVec.insert(newVec.end(), nums2.begin(), nums2.end());
        sort(newVec.begin(), newVec.end());
        int n=newVec.size() ;
        return medianValue(newVec, n);       
    } 
        
};