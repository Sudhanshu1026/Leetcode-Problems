class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {
        for (int k = 1; k <= 60; ++k) {
            long long t = 1LL * num1 - 1LL * k * num2;
            if (t <= 0) continue; // Must be positive
            int bits = __builtin_popcountll(t); // Number of set bits
            if (bits <= k && k <= t) {
                return k;
            }
        }
        return -1;
    }
};
