class Solution {
public:
    int findClosest(int x, int y, int z) {
      int x1 = z - x;
      int x2 = x-z;
      int x3 = max(x1, x2);   

      int y1 = z - y;
      int y2 = y-z;
      int y3 = max(y1, y2);

      if(x3 > y3){
        return 2;
      }        
      else if(y3 > x3){
        return 1;
      }
      return 0;
      

    }
   

   
};