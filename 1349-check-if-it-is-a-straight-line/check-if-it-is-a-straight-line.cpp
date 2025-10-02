class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int n=coordinates.size();
         
        //  int X=cordinates[0][0];
        //  int Y=cordinates[0][1];

        //  int x,y;

        //  int i=1;
        int i=2;
        while(i<n){

            if((coordinates[i][1] - coordinates[i-1][1]) * (coordinates[i-1][0] - coordinates[i-2][0]) ==
                (coordinates[i-1][1] - coordinates[i-2][1]) * (coordinates[i][0] - coordinates[i-1][0]))
                i++;
                else
                return false;
        }
        return true;
        
    }
};