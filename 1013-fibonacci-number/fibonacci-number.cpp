class Solution {
public:
    int fib(int n) {

        // We will solve this through Recursion method

        if(n==0)
        return 0;    // Base case 1st

      if(n==1)
      return 1;   // Base case 2nd

        return fib(n-1)+fib(n-2);
    }
};