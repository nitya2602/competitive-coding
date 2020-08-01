class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<string> aux(strs.begin(), strs.end());
        for(int i=0; i<aux.size(); i++)
            sort(aux[i].begin(), aux[i].end());
        vector<string> help(aux.begin(), aux.end());
        sort(help.begin(), help.end());
        help.erase(unique(help.begin(), help.end()), help.end());
        vector<vector<string>> ans;
        for(int i=0; i<help.size(); i++)
        {
            vector<string> temp;
            for(int j=0; j<aux.size(); j++)
            {
                if(aux[j]==help[i])
                    temp.push_back(strs[j]);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};
