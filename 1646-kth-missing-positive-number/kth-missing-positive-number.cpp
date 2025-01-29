#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        unordered_map<int, bool> hash; // Hash map to store presence of numbers in arr

        // Store all elements of arr in hash map
        for (int num : arr) {
            hash[num] = true;
        }

        int missingCount = 0, num = 1;

        // Iterate over natural numbers and count missing ones
        while (true) {
            if (hash.find(num) == hash.end()) { // If num is not in arr, it's missing
                missingCount++;
                if (missingCount == k) {
                    return num; // Return the k-th missing number
                }
            }
            num++; // Move to the next number
        }
        return -1; // Should never reach here
    }
};
