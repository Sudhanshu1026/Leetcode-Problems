class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {

        unordered_map<int,int>m;
        m[0]=1;                       //Initialisation of map with 0 -> Handle 0 sum edge case

        int prefixsum=0,rem,total=0;

        for(int i=0;i<nums.size();i++){

            prefixsum+=nums[i];
            rem = prefixsum % k;  // Prefix sum and rem nikal lo ->for each index element

            if(rem<0)   //Agar rem -ve hai to +ve bnao
            rem=rem+k;


            if(m.count(rem))  //Agar rem already aa chuka hai..map me to total ko bdhao 
            {total+=m[rem];
            m[rem]++;
            }
            else
            m[rem]=1;


        }
        return total;
    }
};