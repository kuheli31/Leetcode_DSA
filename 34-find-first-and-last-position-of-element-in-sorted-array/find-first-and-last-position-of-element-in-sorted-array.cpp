class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int lower = -1, higher = -1;
        int low = 0, high = nums.size() - 1;

        // Find the first occurrence
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] == target) {
                lower = mid;
                high = mid - 1; // Move left to find the first occurrence
            } else if (nums[mid] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        low = 0, high = nums.size() - 1;

        // Find the last occurrence
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] == target) {
                higher = mid;
                low = mid + 1; // Move right to find the last occurrence
            } else if (nums[mid] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return {lower, higher};
    }
};