class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>m;
        m[0]=1;
        int total=0;
        int prefixsum=0;

        for(int i=0;i<nums.size();i++){
            prefixsum+=nums[i];

            //Check If prefixSum-k already seem in map
            if(m.count(prefixsum-k))
            {
                total +=m[prefixsum-k];
                m[prefixsum]++;
            }else
           m[prefixsum]++;
        }
     return total;   
    }
};