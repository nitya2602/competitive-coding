class Solution {
public:
    string reverseVowels(string s) {
        vector<char> str(s.begin(), s.end());
        vector<char> vowels;
        vector<int> index;
        string ans = "";
        for(int i=0; i<str.size(); i++)
        {
            if(str[i]=='a'||str[i]=='e'||str[i]=='i'||str[i]=='o'||str[i]=='u'||str[i]=='A'||str[i]=='E'||str[i]=='I'||str[i]=='O'||str[i]=='U')
            {
                vowels.push_back(str[i]);
                str[i] = '^';
            }
        }
        if(vowels.size()==0)
            return s;
        for(int i=0; i<str.size(); i++)
        {
            if(str[i]=='^')
            {
                ans += vowels.back();
                vowels.pop_back();
            }
            else
                ans += str[i];
        }
        return ans;
    }
};
