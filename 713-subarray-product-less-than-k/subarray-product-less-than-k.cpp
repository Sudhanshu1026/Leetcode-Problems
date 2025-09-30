class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int count =0;
        int product=1;
        int start=0,end=0;
        int n=nums.size();

        while(end<n)
        {
            product *= nums[end];
             
             while(product>=k && start<=end){
                product /= nums[start];
                start++ ;
             }
             count += end-start+1;
             end++;
            
        }
        return count;
    }
};