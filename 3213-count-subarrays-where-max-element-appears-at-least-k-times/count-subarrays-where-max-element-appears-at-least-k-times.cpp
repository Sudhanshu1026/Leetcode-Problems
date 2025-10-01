class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int start=0,end=0,count=0;
        long long total=0;
        int n=nums.size(),maxEle=0;

        //find max Element
        for(int i=0;i<n;i++)
        maxEle=max(maxEle,nums[i]);

        while(end<n){
            if(nums[end]==maxEle)
            count++;

            while(count==k){
                total +=n -end;      //Update Answer 'total'
                if(nums[start]==maxEle) //Check if first ele removed is maxEle
                count--;

                start++;

            }

          end++;
        }
        return total;
        
    }
};