class Solution {
public:


void subseq(vector<int>& arr,int index,int n,vector<vector<int> >& ans,vector<int>& temp){  //we will pass temp as refernce to reduce space complexity and will use same temp again and again for every subsequence.
 
 
//Stopping condition
if(index==n){
    ans.push_back(temp);
    return;
}


    //Not included
    subseq(arr,index+1,n,ans,temp);
    //Included
    temp.push_back(arr[index]);
    subseq(arr,index+1,n,ans,temp);

// to reduce space complexity as we are using same temp for each subseq , So it is required to empty it before moving to next step
temp.pop_back();
}

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int> >ans;
        vector<int>temp;

        subseq(nums,0,nums.size(),ans,temp);


        return ans;

        
    }
};