class Solution {
public:
    int lengthOfLastWord(string s) {
        int count = 0;
        
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != ' ') {
                count++;  // counting characters of current word
            } else {
                // reset count only when next character is not space
                if (i + 1 < s.size() && s[i + 1] != ' ')
                    count = 0;
            }
        }
        
        return count;
    }
};
