class Solution {
public:
    int maxPower(string s) {
        int _max = 1;
        for(int i=0; i<s.length()-1; i++)
        {
            int count = 1;
            while(i<s.length()-1 && s[i] == s[i+1])
            {
                count++;
                i++;
            }
            _max = max(_max, count);
        }
        return _max;
    }
};