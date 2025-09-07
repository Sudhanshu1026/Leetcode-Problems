class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> ans;
        
        // if odd, add 0 first
        if (n % 2 != 0) {
            ans.push_back(0);
        }
        
        // add pairs (i, -i)
        for (int i = 1; i <= n / 2; i++) {
            ans.push_back(i);
            ans.push_back(-i);
        }
        
        return ans;
    }
};
