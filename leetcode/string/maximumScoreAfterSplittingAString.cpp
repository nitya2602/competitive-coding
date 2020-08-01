//both the partitions should be non-empty

class Solution {
public:
    int maxScore(string s) {
        int zero = 0;
        int one = 0;
        if(s.size()==0)
            return 0;
        for(int i=0; i<s.size(); i++)
        {
            if(s[i]=='1')
                one++;
        }
        if(one==s.size() || one==0)
            return s.size()-1;
        int score = 0;
        for(int i=0; i<s.size()-1; i++)
        {
            if(s[i]=='0')
                zero++;
            else
                one--;
            score = max(score, one+zero);
        }
        return score;
    }
};
