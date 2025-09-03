class Solution {
public:
    bool reorderedPowerOf2(int n) {
        // Precompute all power of 2 digit signatures
        static unordered_set<string> powerSet;
        if (powerSet.empty()) {
            for (int i = 0; i < 31; i++) {
                int num = 1 << i; // 2^i
                string s = to_string(num);
                sort(s.begin(), s.end());
                powerSet.insert(s);
            }
        }

        // Compute signature of n
        string s = to_string(n);
        sort(s.begin(), s.end());

        return powerSet.count(s);
    }
};
