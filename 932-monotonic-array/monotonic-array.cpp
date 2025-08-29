class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int n = nums.size();
        if (n <= 2) return true; // single element or pair is always monotonic



        // Check increasing order
        int i = 1;
        while (i < n && nums[i] >= nums[i-1]) 
        i++;
        if (i == n) 
        return true; // whole array checked for increasing




        // Check decreasing order
        i = 1;
        while (i < n && nums[i] <= nums[i-1]) 
        i++;
        if (i == n)
         return true; // whole array checked for decreasing


        // Neither increasing nor decreasing
        return false;
    }
};
