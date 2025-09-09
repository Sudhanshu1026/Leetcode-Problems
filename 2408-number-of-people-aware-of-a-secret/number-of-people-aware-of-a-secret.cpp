class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        const int MOD = 1e9 + 7;
        vector<long long> dp(n + 1, 0); // dp[i] = new people who learn secret on day i
        dp[1] = 1;
        
        long long sharing = 0; // number of people who can share today
        
        for (int day = 2; day <= n; day++) {
            // Add people who become eligible to share today
            if (day - delay >= 1) {
                sharing = (sharing + dp[day - delay]) % MOD;
            }
            // Remove people who forget today
            if (day - forget >= 1) {
                sharing = (sharing - dp[day - forget] + MOD) % MOD;
            }
            // All active sharers share with new people today
            dp[day] = sharing;
        }
        
        long long ans = 0;
        // Count only those who haven’t forgotten by day n
        for (int day = n - forget + 1; day <= n; day++) {
            if (day >= 1) ans = (ans + dp[day]) % MOD;
        }
        return ans;
    }
};
