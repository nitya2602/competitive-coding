class Solution {
public:
    string sortString(string s) {
        int count[26] = {0};
        string ans = "";
        for(int i=0; i<s.size(); i++)
        {
            count[s[i]-'a']++;
        }
        int flag = 0;
        while(flag<s.size())
        {
            for(int i=0; i<26; i++)
                if(count[i]>0)
                {
                    flag++;
                    count[i]--;
                    ans += 'a'+i;
                }
            for(int i=25; i>=0; i--)
                if(count[i]>0)
                {
                    flag++;
                    count[i]--;
                    ans += 'a'+i;
                }
        }
        return ans;
    }
};
