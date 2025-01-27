class Solution {
public:
    int func(vector<int>& piles, int hourly) {
        long long totalHours = 0;
        for (int i = 0; i < piles.size(); i++) {
            totalHours += (piles[i] + hourly - 1) / hourly; // Equivalent to ceil(piles[i] / hourly)
        }
        return totalHours;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        long long high = *max_element(piles.begin(), piles.end()); // Largest pile size
        long long low = max(1LL, accumulate(piles.begin(), piles.end(), 0LL) / h); // Minimum speed cannot be smaller than the average bananas per hour
        long long ans = high; // Initialize answer as the largest pile size

        while (low <= high) {
            long long mid = low + (high - low) / 2;
            long long totalHours = func(piles, mid);

            if (totalHours <= h) {
                ans = mid; // Update the answer to the current valid speed
                high = mid - 1; // Try to find a smaller valid speed
            } else {
                low = mid + 1; // Increase speed to reduce total hours
            }
        }
        return ans;
    }
};
