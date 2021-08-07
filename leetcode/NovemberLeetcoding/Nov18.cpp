class Solution {
public:
    static bool compare(const vector<int>& a, const vector<int>& b)
    {
        if(a[0] < b[0])
            return true;
        return false;
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int i = 0;
        if(intervals.size() == 0 || intervals.size() == 1)
            return intervals;
        sort(intervals.begin(), intervals.end(), compare);
        vector<vector<int>> ans;
        vector<int> temp;
        while(i < intervals.size() - 1)
        {
            temp = intervals[i];
            int j = i + 1;
            while(j <= intervals.size()-1 && temp[1] >= intervals[j][0])
            {
                temp[1] = max(temp[1], intervals[j][1]);
                j++;
            }
            ans.push_back(temp);
            i = j;
        }
        if(i <= intervals.size() - 1)
            ans.push_back(intervals[intervals.size() - 1]);
        return ans;
    }
};