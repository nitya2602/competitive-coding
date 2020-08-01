class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int count = 0;
        
        //if we don't sort then we might end up using 
        //some cookie that could have been used for a larger child
        //while the current child could have been satisfied with a smaller cookie
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        for(int i=0; i<g.size(); i++)
        {
            for(int j=0; j<s.size(); j++)
            {
                if(s[j]>=g[i])
                {
                    s[j] = -1;
                    count++;
                    break;
                }
            }
        }
        return count;
    }
};
