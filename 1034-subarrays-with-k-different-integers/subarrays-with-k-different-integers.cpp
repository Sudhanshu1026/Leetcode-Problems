class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {

    //Exact(k)=Atleaast(k)-Atleast(k+1);
     
     //Find Atleast(k)
     unordered_map<int,int>freq;

     int total1=0,start=0,end=0,count=0,n=nums.size();

     while(end<n){
        freq[nums[end]]++;   //Add freq of that number 

        if(freq[nums[end]]==1)  //New number found
        count++;

        while(count==k){       //Decrease the windoe size till "count=k"
            total1+=n-end;
            freq[nums[start]]--;
             
             if(freq[nums[start]]==0)
             count--;

            start++;
        }
        end++;     //Increase the window size until we get "count==k"
     }



      //Find Atleast(k+1)

     int total2=0;
     start=0,end=0,count=0,k++;
     freq.clear();

       while(end<n){
        freq[nums[end]]++;   //Add freq of that number 

        if(freq[nums[end]]==1)  //New number found
        count++;

        while(count==k){       //Decrease the windoe size till "count=k"
            total2+=n-end;
            freq[nums[start]]--;
             
             if(freq[nums[start]]==0)
             count--;

            start++;
        }
        end++;     //Increase the window size until we get "count==k"
     }
    
        return total1-total2;
    }
};