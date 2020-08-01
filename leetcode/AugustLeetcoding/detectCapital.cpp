class Solution {
public:
    bool detectCapitalUse(string word) {
        int count = 0;
        for(int i=0; i<word.length(); i++)
        {
            if(word[i]-'A'>=0 && word[i]-'A'<=25)
                count++;
        }
        if(count==word.length() || count==0)
            return true;
        if(count==1 && (word[0]-'A'>=0 && word[0]-'A'<=25))
            return true;
        else
            return false;
        return false;
    }
};
