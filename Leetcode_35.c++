#include <stdio.h>

int searchInsert(int* nums, int numsSize, int target) {
    int low = 0, high = numsSize - 1, mid;
    while (low <= high) {
        mid = low + (high - low) / 2;
        if (target == nums[mid]) {
            return mid;
        } else if (target < nums[mid]) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return low;
}
