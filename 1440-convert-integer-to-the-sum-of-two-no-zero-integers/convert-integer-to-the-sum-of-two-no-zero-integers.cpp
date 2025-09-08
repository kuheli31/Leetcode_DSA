class Solution {
public:
    // Helper function to check if a number contains 0 in its decimal representation
    bool hasZero(int num) {
        while (num > 0) {
            if (num % 10 == 0)
                return true;
            num /= 10;
        }
        return false;
    }

    vector<int> getNoZeroIntegers(int n) {
        for (int a = 1; a < n; ++a) {
            int b = n - a;
            if (!hasZero(a) && !hasZero(b)) {
                return {a, b};
            }
        }
        
        return {};
    }
};
