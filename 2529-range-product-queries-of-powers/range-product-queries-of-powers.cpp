class Solution {
public:
    const int MOD = 1e9+7;

    long long modPow(long long a, long long b, long long m) {
        long long res = 1;
        while (b > 0) {
            if (b & 1) res = (res * a) % m;
            a = (a * a) % m;
            b >>= 1;
        }
        return res;
    }

    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        // Step 1: Build powers[] from set bits of n
        vector<long long> powers;
        for (int i = 0; i < 32; i++) {
            if (n & (1 << i)) {
                powers.push_back(1LL << i);
            }
        }

        int m = powers.size();

        // Step 2: Compute prefix products
        vector<long long> prefix(m);
        prefix[0] = powers[0] % MOD;
        for (int i = 1; i < m; i++) {
            prefix[i] = (prefix[i-1] * powers[i]) % MOD;
        }

        // Step 3: Answer queries
        vector<int> ans;
        for (auto &q : queries) {
            int l = q[0], r = q[1];
            long long product = prefix[r];
            if (l > 0) {
                // divide by prefix[l-1], i.e. multiply by modular inverse
                long long inv = modPow(prefix[l-1], MOD-2, MOD);
                product = (product * inv) % MOD;
            }
            ans.push_back((int)product);
        }
        return ans;
    }
};
