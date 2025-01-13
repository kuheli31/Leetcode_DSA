class Solution {
public:
    void rotate(vector<int>& nums, int k) 
    {
        int i;
        int n=nums.size();
         k = k % n;           // Handle cases where k > n
        if (k == 0 || n <= 1) return; // No rotation needed for these cases
         vector<int> temp(k); // Create a temporary array to store last k elements

        // Step 1: Store the last k elements
        for (int i = 0; i < k; i++) {
            temp[i] = nums[n - k + i];
        }

        // Step 2: Shift the remaining elements to the right
        for (int i = n - k - 1; i >= 0; i--) {
            nums[i + k] = nums[i];
        }

        // Step 3: Place the stored k elements at the beginning
        for (int i = 0; i < k; i++) {
            nums[i] = temp[i];
        }
    }
};