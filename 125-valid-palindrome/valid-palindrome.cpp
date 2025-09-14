class Solution {
public:
    bool isPalindrome(string s) {
    int left = 0;
    int right = s.size() - 1;

    while (left < right) {
        // Move left until found alphanumeric
        while (left < right && !isalnum(s[left])) {
            left++;
        }
        // Move right until found alphanumeric
        while (left < right && !isalnum(s[right])) {
            right--;
        }

        // Convert both to lower case -> Compare 
        if (tolower(s[left]) != tolower(s[right])) {
            return false;
        }

        left++;
        right--;
    }

    return true;
}
    
};