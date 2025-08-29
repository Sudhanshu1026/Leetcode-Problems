class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";
        
        string prefix = strs[0];  // Start with the first string as the prefix
        
        for (int i = 1; i < strs.size(); ++i) {
            // Compare the prefix with each string and shorten it until it matches
            while (strs[i].find(prefix) != 0) {
                prefix = prefix.substr(0, prefix.size() - 1);
                if (prefix.empty()) return "";
            }
        }
        
        return prefix;
    }
};
