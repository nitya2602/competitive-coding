class Solution {
public:
    int titleToNumber(string s) {
        int colno = 0;
        for(int i=0; i<s.size(); i++)
        {
            colno = colno*26 + (s[i]-'A') + 1;
        }
        return colno;
    }
};
