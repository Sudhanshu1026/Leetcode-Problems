class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<int> height(n, 0);
        int ans = 0;

        for (int i = 0; i < m; i++) {
            // Step 1: Update histogram heights
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 0) height[j] = 0;
                else height[j] += 1;
            }

            // Step 2: Count submatrices ending at row i
            for (int j = 0; j < n; j++) {
                int minH = height[j];
                for (int k = j; k >= 0 && minH > 0; k--) {
                    minH = min(minH, height[k]);
                    ans += minH;
                }
            }
        }
        return ans;
    }
};
