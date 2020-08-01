class Solution {
public:
    int maxPower(string s) {
        int count = 0;
        int max = 1;
        for(int i=0; i<s.size()-1; i++)
        {
            count = 1;
            while(s[i]==s[i+1])
            {
                count++;
                i++;
            }
            if(count>max)
                max = count;
        }
        return max;
    }
};
