class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int>d; //Store indices of elements inside window  
        vector<int>ans;  //Store max values from window.
         int n = nums.size();

       // Initialization Part (0 to k-1)
        
        for(int i=0;i<k-1;i++){
            if(d.empty())
            d.push_back(i);
            else{
                while( !d.empty() && nums[i]>nums[d.back()] )//Check if new element added is greater
               { d.pop_back();}

                d.push_back(i);
            
            }
        }
      
       // Final Part (k-1 to n)
       for(int i=k-1;i<n;i++){
        while( !d.empty() && nums[i]>nums[d.back()] )//Check if new element added is greater
                  { d.pop_back();}

                d.push_back(i);

                if(d.front()<= i-k ) //Check if front of queue is out of window?
                d.pop_front();

                ans.push_back(nums[d.front()]);

       }

     return ans;
    }
};