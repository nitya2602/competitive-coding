class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
       set<string> set;
        for(int i = 0; i<emails.size(); i++)
        {
            string s = emails[i];
            string aux = "";
            int domain = 0, plus = 0;
            for(int j = 0; j < s.size(); j++)
            {
                if(s[j] == '@')
                {
                    domain = 1;
                    plus = 0;
                }
                else if(s[j] == '+' && domain == 0)
                {
                    plus = 1;
                }
                if(plus == 1) continue;
                if(s[j] == '.' && domain == 0)
                    continue;
                aux += s[j];
            }
            set.insert(aux);
        }
        return set.size();
}
};
    