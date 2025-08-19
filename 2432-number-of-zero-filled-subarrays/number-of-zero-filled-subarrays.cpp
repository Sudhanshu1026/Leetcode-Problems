#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long count = 0, currentStreak = 0;
        
        for (int num : nums) {
            if (num == 0) {
                currentStreak++;  // extend zero streak
                count += currentStreak;  // add all subarrays ending here
            } else {
                currentStreak = 0;  // reset streak
            }
        }
        
        return count;
    }
};