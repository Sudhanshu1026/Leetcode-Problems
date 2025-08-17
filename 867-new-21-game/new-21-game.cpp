#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double new21Game(int n, int k, int maxPts) {
        // Edge case: If Alice never needs to draw, or if n is large enough
        if (k == 0 || n >= k + maxPts) return 1.0;

        vector<double> dp(n + 1, 0.0);
        dp[0] = 1.0;  // start with 0 points

        double windowSum = 1.0; // sum of probabilities in the sliding window
        double result = 0.0;

        for (int i = 1; i <= n; i++) {
            dp[i] = windowSum / maxPts;

            if (i < k) {
                // Still in drawing zone → add to window
                windowSum += dp[i];
            } else {
                // Already stopped, accumulate result
                result += dp[i];
            }

            if (i - maxPts >= 0) {
                // Slide the window
                windowSum -= dp[i - maxPts];
            }
        }

        return result;
    }
};
