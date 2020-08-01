class Solution {
public:
    bool isValid(string s) {
        deque<char> res;
        for(int i=0; i<s.length(); i++)
        {
            if(s[i]=='(' || s[i]=='{' || s[i]=='[')
                res.push_front(s[i]);
            else
            {
                 if(s[i]==')')
                 {
                     if(res.empty())
                        return false;
                     else if(res.front()=='(')
                       res.pop_front();
                     else
                         return false;
                 }
                else if(s[i]=='}')
                 {
                     if(res.empty())
                        return false;
                     else if(res.front()=='{')
                       res.pop_front();
                    else
                        return false;
                 }
                else
                 {
                     if(res.empty())
                        return false;
                     else if(res.front()=='[')
                       res.pop_front();
                    else
                        return false;
                }
        }
    }
        return res.empty();
    }
};
