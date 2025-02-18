class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) 
    {
        int n1 = nums1.size();
        int n2 = nums2.size();
        unordered_map<int, int> mpp; // Stores index of each element in nums2
        vector<int> result(n1, -1);  // Initialize result with -1

        // Step 1: Store the index of each element in nums2
        for (int j = 0; j < n2; j++) {
            mpp[nums2[j]] = j;
        }

        // Step 2: Find next greater element for nums1[i] in nums2
        for (int i = 0; i < n1; i++) {
            int index = mpp[nums1[i]]; // Get the index of nums1[i] in nums2
            for (int j = index + 1; j < n2; j++) { // Search for next greater
                if (nums2[j] > nums1[i]) {
                    result[i] = nums2[j];
                    break;
                }
            }
        }

        return result;
    }
};