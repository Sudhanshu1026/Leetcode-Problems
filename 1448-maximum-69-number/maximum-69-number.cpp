class Solution {
public:
    int maximum69Number (int num) {
        vector<int>digits;

         while (num > 0) {
        digits.push_back(num % 10);          // extract last digit
        num /= 10;                           // remove last digit
    }

    reverse(digits.begin(), digits.end()); // reverse to correct order

         for(int i=0;i<digits.size();i++)
         {
            if(digits[i]== 6 ){
                digits[i]= 9 ;
                break;
            }
           
         }
        
         // rebuild the number
        int result = 0;
        for (int i=0;i<digits.size();i++) {
            result = result * 10 + digits[i];
        }

        return result;

    }
};