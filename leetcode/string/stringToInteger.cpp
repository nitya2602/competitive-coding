class Solution {
public:
    int myAtoi(string s) {
        int i = 0;
        while(s[i] == ' ' && i < s.length())
            i++;
        if(i == s.length())
            return 0;
        char sign;
        if(!(s[i] == '+') && !(s[i] == '-') && !(s[i] >= '0' && s[i] <= '9'))
            return 0;
        if(s[i] == '+' || s[i] == '-')
            sign = s[i++];
        else{
            sign = '+';
        }
        int ans = 0;
        string temp = "";
        int flag = 0;
        while(i < s.length() && (s[i] >= '0' && s[i] <= '9'))
        {
            if(ans > INT_MAX/10)
            {
                if(sign == '-')
                    return INT_MIN;
                return INT_MAX;
            }
            if(ans == INT_MAX/10)
            {
                if(s[i]-'0' > 7)
                {
                    if(sign == '-')
                        return INT_MIN;
                    return INT_MAX;
                }      
            }
            ans = ans*10 + (s[i] - '0');
            cout<<ans<<" ";
            i++;
        }
        if(sign == '-')
            ans = -ans;
        return ans;
    }
};