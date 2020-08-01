// don't divide to find slope as diision by 0 creates problem

class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        if(coordinates.size()==2 || coordinates.size()==1)
            return true;
        int x = coordinates[0][0];
        int y = coordinates[0][1];
        int x_diff = coordinates[1][0] - x;
        int y_diff = coordinates[1][1] - y;
        for(int i=2; i<coordinates.size(); i++)
        {
            if((coordinates[i][1]-y)*x_diff != (coordinates[i][0]-x)*y_diff)
                return false;
        }
        return true;
    }
};


