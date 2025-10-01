class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int,int>count;
        int start=0,end=0,len=0;
        
        while(end<nums.size()){
            //Update count of number in map
            count[nums[end]]++;

            //Check if  count exceeds k
            while(count[nums[end]]>k) //Reduce window size
            {
                count[nums[start]]--;
                start++;
            }
            //Update len
            len = max(len,end-start+1);
            end++;    //else->increse window size

        }
         return len;
    }
};