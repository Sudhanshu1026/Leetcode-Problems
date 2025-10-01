class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        int start=0,end=0;
        int size=INT_MAX;

        while(end<n){
            sum+=nums[end];

               while(sum>=target)
               {
                size=min(size,end-start+1);
                sum-=nums[start];
                start++;
               }
               end++;
        }

          if(size==INT_MAX)
          return 0;
          else
          return size;
    }
};