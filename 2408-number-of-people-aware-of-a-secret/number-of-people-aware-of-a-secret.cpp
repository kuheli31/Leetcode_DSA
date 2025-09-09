class Solution {
public:
    int MOD = 1e9 + 7;
    int n, delay, forget;
    vector<int> memo;

    // f(day) = number of people who first learn the secret on "day"
    int solve(int day) {
        if (day == 1) return 1;   // on day 1, only one person knows
        if (day <= 0) return 0;

        if (memo[day] != -1) return memo[day];

        long long result = 0;
        // contributors are from [day - forget + 1, day - delay]
        for (int prev = day - forget + 1; prev <= day - delay; prev++) {
            if (prev > 0) {
                result = (result + solve(prev)) % MOD;
            }
        }
        return memo[day] = (int)result;
    }

    int peopleAwareOfSecret(int n, int delay, int forget) {
        this->n = n;
        this->delay = delay;
        this->forget = forget;
        memo.assign(n + 1, -1);

        long long total = 0;
        // only people who still remember on day n
        for (int day = n - forget + 1; day <= n; day++) {
            if (day > 0) total = (total + solve(day)) % MOD;
        }
        return total;
    }
};