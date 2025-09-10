class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        int m = languages.size();
        
        // Convert to sets for quick lookup
        vector<unordered_set<int>> knows(m+1);
        for(int i=0; i<m; i++) {
            for(int lang : languages[i]) {
                knows[i+1].insert(lang);
            }
        }
        
        // Collect users involved in conflicts
        unordered_set<int> conflictUsers;
        for(auto &f : friendships) {
            int u = f[0], v = f[1];
            bool ok = false;
            for(int lang : knows[u]) {
                if(knows[v].count(lang)) { ok = true; break; }
            }
            if(!ok) {  // no common language
                conflictUsers.insert(u);
                conflictUsers.insert(v);
            }
        }
        
        // If no conflicts, answer is 0
        if(conflictUsers.empty()) return 0;
        
        // Try teaching each language
        int ans = INT_MAX;
        for(int lang=1; lang<=n; lang++) {
            int teach = 0;
            for(int u : conflictUsers) {
                if(!knows[u].count(lang)) teach++;
            }
            ans = min(ans, teach);
        }
        
        return ans;
    }
};
