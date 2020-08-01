class Solution {
public:
    int firstUniqChar(string s) {
        map<char, int> store;
        for(const auto &st : s)
        {
            store[st]++;
        }
        vector<char> uni;
        for(const auto &m : store)
        {
            if(m.second==1)
                uni.push_back(m.first);
        }
        if(uni.size()==0)
            return -1;
        int index = s.size();
        for(int i=0; i<uni.size(); i++)
        {
            for(int j=0; j<s.size(); j++)
        {
            if(s[j]==uni[i])
            {
                if(j<index)
                    index = j;
            }
        }
        }
        return index;
    }
};
