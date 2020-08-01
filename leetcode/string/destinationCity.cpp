class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        vector<string> aux(1);
        vector<string> first;
        vector<string> second;
        for(int i=0; i<paths.size(); i++)
        {
            first.push_back(paths[i][0]);
            second.push_back(paths[i][1]);
        }
        sort(first.begin(), first.end());
        sort(second.begin(), second.end());
        set_difference(second.begin(), second.end(), first.begin(), first.end(), aux.begin());
        return aux[0];
    }
};
