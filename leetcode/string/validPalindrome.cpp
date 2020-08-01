class Solution {
public:
    bool isPalindrome(string s) {
        //converting to lower case
        for_each(s.begin(), s.end(), [](char & c){
    c = tolower(c);
});
        
        string str = "";
        //removing punctuation and spaces
        for(int i=0; i<s.size(); i++)
            if(s[i]<='z' && s[i]>='a' || (s[i]>='0' && s[i]<='9'))
                str += s[i];
        int i, j;
        if(str.size()%2==0)
        {
            i = str.size()/2 - 1;
            j = i+1;
            while(i>=0 && j<str.size())
            {
                if(str[i]!=str[j])
                    return false;
                i--;
                j++;
            }
        }
        else
        {
            i = str.size()/2 - 1;
            j = i+2;
            while(i>=0 && j<str.size())
            {
                if(str[i]!=str[j])
                    return false;
                i--;
                j++;
            }
        }
        return true;
    }
};
