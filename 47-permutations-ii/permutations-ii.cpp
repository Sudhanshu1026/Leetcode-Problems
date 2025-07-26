class Solution {
public:

   void permute(vector<int>&arr,vector<vector<int> > &ans,int index){
    //Base cases
    if(index==arr.size()){
        ans.push_back(arr);
        return;
    }


//Bool type vector 'use' to track the status of a num : whether used or not.
vector<bool>use(21,0);

for(int i=index;i<arr.size();i++){

    if(use[arr[i]+10]==0){
      swap(arr[index],arr[i]);
      permute(arr,ans,index+1);
      swap(arr[index],arr[i]);
      use[arr[i]+10]=1;

    }
}

   }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>>ans;
       permute(nums,ans,0);

       return ans;


    }
};