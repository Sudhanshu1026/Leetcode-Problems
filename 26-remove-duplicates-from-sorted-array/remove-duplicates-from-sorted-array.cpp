class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        int prev=0,curr=1; // using these two pointers to track array
          
           int k=1; 

          while(curr<nums.size()){
         // Both digits are same
         if(nums[prev]==nums[curr])
            curr++;
         else // New digits found
         {
            nums[k]=nums[curr]; // Place unique element in correct place
            k++;
            prev=curr;
            curr++;
         }
            }

      return k;
    }
};