class Solution {
public:
    int maxFreqSum(string s) {
        vector<int>freq(26,0);
     
     //Storing frequency of each letter in Frequency vector
        for(int i=0;i<s.size();i++){
            freq[s[i]-'a']++;
        }


    int maxConst=0,maxVowel=0;

        //Iterate to Frequency vector to get max freq
        for(int i=0;i<26;i++){

            if(i==0 || i==4 || i==8 || i==14 || i==20){
                maxVowel=max(freq[i],maxVowel);
            }
            else{
                maxConst=max(freq[i],maxConst);
            }
        }


        return maxVowel+maxConst;

    }
};