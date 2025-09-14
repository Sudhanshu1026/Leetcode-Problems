class Solution {
public:
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        unordered_set<string> exact(wordlist.begin(), wordlist.end());

        unordered_map<string, string> caseMap;
        unordered_map<string, string> vowelMap;

        auto devowel = [](string s) {
            for (char &c : s) {
                if (c=='a' || c=='e' || c=='i' || c=='o' || c=='u') {
                    c = '*';
                }
            }
            return s;
        };

        for (string w : wordlist) {
            string lower;
            for (char c : w) lower.push_back(tolower(c));

            if (!caseMap.count(lower)) {
                caseMap[lower] = w;
            }
            string mask = devowel(lower);
            if (!vowelMap.count(mask)) {
                vowelMap[mask] = w;
            }
        }

        vector<string> ans;
        for (string q : queries) {
            if (exact.count(q)) {
                ans.push_back(q);
                continue;
            }
            string lower;
            for (char c : q) lower.push_back(tolower(c));

            if (caseMap.count(lower)) {
                ans.push_back(caseMap[lower]);
            } else {
                string mask = devowel(lower);
                if (vowelMap.count(mask)) {
                    ans.push_back(vowelMap[mask]);
                } else {
                    ans.push_back("");
                }
            }
        }
        return ans;
    }
};