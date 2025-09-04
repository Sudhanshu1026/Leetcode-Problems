class Solution {
public:
    int findClosest(int x, int y, int z) {
      int x1 = z - x;
      int x2 = x-z;
       x2 = max(x1, x2);   

      int y1 = z - y;
      int y2 = y-z;
       y2 = max(y1, y2);

      if(x2 > y2){
        return 2;
      }        
      else if(y2 > x2){
        return 1;
      }
      return 0;
      

    }
   

   
};