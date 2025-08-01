class Solution {
public:
    bool isPalindrome(int x) {

if(x<0)
return 0;

        vector<int>number;
        //Putting digits into the number vector
int remainder,digits=0;
        while(x){
          remainder=x%10;
          number.push_back(remainder);
          digits++;
          x=x/10;  
        }
        
        //Digit=no's of digits in X
        //Number = All digits in form of vector

        int start=0,end=digits-1;
        while(start<=end){
            if(number[start]==number[end])
            {
                start++;
                end--;
            }
            else
            return 0;
        }
      return 1;

    }
};