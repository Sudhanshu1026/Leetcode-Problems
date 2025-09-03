class Solution {
public:
    const int MOD = 1e9 + 7;
    int n, x;
    vector<vector<int>> dp;

    int solve(int curr, int target) {
        if (target == 0) return 1;       // found valid set
        if (curr > n) return 0;          // no more numbers
        long long p = pow(curr, x);
        if (p > target) return 0;        // too large

        if (dp[curr][target] != -1) return dp[curr][target];

        // Option 1: skip this number
        long long ways = solve(curr+1, target) % MOD;

        // Option 2: take this number if possible
        if (p <= target) {
            ways += solve(curr+1, target - p);
            ways %= MOD;
        }

        return dp[curr][target] = ways;
    }

    int numberOfWays(int N, int X) {
        n = N; x = X;
        dp.assign(n+2, vector<int>(n+1, -1));
        return solve(1, n);
    }
};
