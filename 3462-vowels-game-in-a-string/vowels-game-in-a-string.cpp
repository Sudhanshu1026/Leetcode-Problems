class Solution {
public:
    bool doesAliceWin(string s) {
        for (char c : s) {
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
                return true; // Alice wins if any vowel exists
        }
        return false; // No vowels → Alice can't move → she loses
    }
};
