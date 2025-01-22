class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int ind = -1; // Initialize index to -1 to indicate no valid index found yet.
        int n = nums.size(); // Get the size of the input array.

        // Step 1: Find the first index `ind` from the right where nums[ind] < nums[ind+1].
        for (int i = n - 2; i >= 0; i--) { // Start from the second-last element and move left.
            if (nums[i] < nums[i + 1]) { // Check if the current number is smaller than the next.
                ind = i; // Update `ind` to the current index.
                break; // Break the loop as we found the first decreasing point.
            }
        }

        // Step 2: If no such index is found, the array is the last permutation.
        if (ind == -1) { 
            reverse(nums.begin(), nums.end()); // Reverse the entire array to get the smallest permutation.
            return; // Return as we are done.
        }

        // Step 3: Find the smallest number to the right of `ind` that is larger than nums[ind].
        for (int i = n - 1; i > ind; i--) { // Start from the last element and move left.
            if (nums[i] > nums[ind]) { // Find the first number greater than nums[ind].
                swap(nums[i], nums[ind]); // Swap nums[i] and nums[ind] to form the next larger number.
                break; // Break as the correct swap is performed.
            }
        }

        // Step 4: Reverse the subarray to the right of `ind` to make it the smallest arrangement.
        reverse(nums.begin() + ind + 1, nums.end()); 
        return; // Return as the next permutation is now formed.
    }
};
