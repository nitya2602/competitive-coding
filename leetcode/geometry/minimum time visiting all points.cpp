class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        vector<vector<int>> diff;
        vector<int> v;
        v.push_back(0);
        v.push_back(0);
        int count = 0;
        for(int i=0; i<points.size()-1; i++)
        {
            v[0] = abs(points[i][0] - points[i+1][0]);
            v[1] = abs(points[i][1] - points[i+1][1]);
            diff.push_back(v);
        }
        for(int i=0; i<diff.size(); i++)
        {
            if(diff[i][0]<diff[i][1])
                count+=diff[i][0];
            else
                count+=diff[i][1];
            count+=abs(diff[i][0] - diff[i][1]);
        }
        return count;
    }
};
