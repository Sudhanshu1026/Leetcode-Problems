class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();

        // Step 1: sort the array
        sort(nums.begin(), nums.end());

        // Step 2: fix one element (nums[i]) and use two pointers for the rest
        for (int i = 0; i < n; i++) {
            // Skip duplicate values for i (to avoid same triplet)
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            int left = i + 1;        // second pointer
            int right = n - 1;       // third pointer

            while (left < right) {
                long long sum = (long long)nums[i] + nums[left] + nums[right];

                if (sum == 0) {
                    // Found a triplet
                    ans.push_back({nums[i], nums[left], nums[right]});

                    // Skip duplicates for left
                    while (left < right && nums[left] == nums[left + 1]) left++;
                    // Skip duplicates for right
                    while (left < right && nums[right] == nums[right - 1]) right--;

                    // Move both pointers
                    left++;
                    right--;
                }
                else if (sum < 0) {
                    // Need a bigger sum → move left to right
                    left++;
                }
                else { // sum > 0
                    // Need a smaller sum → move right to left
                    right--;
                }
            }
        }

        return ans;
    }
};