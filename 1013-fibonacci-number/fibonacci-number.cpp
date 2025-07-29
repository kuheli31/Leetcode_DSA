class Solution {
public:
    int fib(int n) {
        int prev1 = 0;
        int prev2 = 1;
        int curr = 0;
        for(int i=0 ; i<n ; i++)
        {
            curr = prev1 + prev2;
            prev2 = prev1;
            prev1 = curr;
        }
        return curr;
    }
};