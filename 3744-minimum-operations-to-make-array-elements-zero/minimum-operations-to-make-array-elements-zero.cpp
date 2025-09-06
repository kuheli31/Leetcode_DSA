class Solution {
public:
    long long solve(int l,int r){
        long long S = 1; // 1 to 3 -> 1 step
        // 4 to 15 -> 2 steps
        // 16 to 63 -> 3 steps 
        //[L to R] range 4^(s-1) to (4^s) - 1

        long long L = 1; //R = 4*L -1
        long long steps = 0;
        while(L <= r){ //within range
            long long R = 4*L - 1;

            long long start = max(L, (long long)l);
            long long end = min(R, (long long)r);

            if(start <= end){
                steps += (end-start+1) * S; // no.of vals * each step-value
            }
            S++; // go for next range
            L = 4*L;
        }

        return steps;

    }
    long long minOperations(vector<vector<int>>& queries) {
        long long res = 0;
        for(auto &q : queries){
            int l = q[0];
            int r = q[1];

            long long steps = solve(l,r);
            res += (steps+1)/2; // ceil
        }

        return res;
    }
};