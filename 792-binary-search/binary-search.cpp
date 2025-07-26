class Solution {
public:
     
     int binarysearch(vector<int>&arr,int start,int end,int target){
          
          //Base case
          if(start>end)
          return -1;


          int mid=start+(end-start)/2;

          if(arr[mid]==target)
          return mid;
          else if(arr[mid]<target)
          return binarysearch(arr,mid+1,end,target);  //Move search to right of mid.
          else
          return binarysearch(arr,start,mid-1,target);  //Move search to left of mid.
     }




    int search(vector<int>& nums, int target) {
        return binarysearch(nums,0,nums.size()-1,target);
    }
};