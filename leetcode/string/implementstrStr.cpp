class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle == "")
            return 0;
        if(needle.size()>haystack.size())
            return -1;
        for(int i=0; i<=haystack.size()-needle.size()+1; i++)
        {
            string temp = haystack.substr(i, needle.size());
            int x = temp.compare(needle);
            if(x==0)
                return i;
        }
        return -1;
    }
};
