class Solution {
public:
    int maxSubArray(vector<int>& nums) 
    {
        int maxSum = INT_MIN; // Initialize maxSum to the smallest integer
        int currentSum = 0; // This will hold the current subarray sum
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            currentSum += nums[i]; // Add the current element to the current sum

            // Update maxSum if currentSum is greater
            if (currentSum > maxSum) {
                maxSum = currentSum;
            }

            // If currentSum drops below 0, reset it to 0
            if (currentSum < 0) {
                currentSum = 0;
            }
        }
        return maxSum; // Return the maximum subarray sum
    }
};