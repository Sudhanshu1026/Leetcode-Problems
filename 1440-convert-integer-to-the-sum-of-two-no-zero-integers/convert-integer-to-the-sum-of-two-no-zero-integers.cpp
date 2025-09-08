class Solution {
public:

  bool isNoZero(int num) { //To check if no cotains 0 or not
    while (num > 0) {
        if (num % 10 == 0) return 0; // contains a zero
        num /= 10;
    }
    return 1;
}
    
      

vector<int> getNoZeroIntegers(int n) {
     vector<int>ans ;
    for (int a = 1; a < n; a++) {
        int b = n - a;
        if (isNoZero(a) && isNoZero(b)) {
           ans.push_back(a);
           ans.push_back(b); 
           return ans; 
        }
    }   
    return {};
}
   
};