class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = "";
        if(strs.size()==0)
            return ans;
        int min = strs[0].length();
        for(int i=1; i<strs.size(); i++)
        {
            if(strs[i].length()<min)
                min = strs[i].length();
        }
        if(min==0)
            return ans;
        
        for(int i=0; i<min; i++)
        {
            for(int j=0; j<strs.size()-1; j++)
            {
                if(strs[j][i]!=strs[j+1][i])
                    return ans;
            }
            ans += strs[0][i];
        }
        return ans;
    }
};
