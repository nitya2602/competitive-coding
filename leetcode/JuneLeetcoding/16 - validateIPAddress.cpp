# too many conditions

class Solution {
public:
    string validIPAddress(string IP) {
        if(IP.size()==0 || IP.size()>40)
            return "Neither";
        if(IP[IP.size()-1]=='.' || IP[IP.size()-1]==':')
            return "Neither";
        if(IP.find('.') != -1)
        {
            vector<string> words;
            string s1 = "";
            IP = IP + ".";
            for(int i=0; i<IP.size(); i++)
            {
                if(IP[i]!='.')
                    s1 += IP[i];
                else
                {
                    words.push_back(s1);
                    s1 = "";
                }
            }
            if(words.size()!=4)
                return "Neither";
            for(int i=0; i<words.size(); i++)
            {
                if(words[i].size()==0)
                    return "Neither";
                if(words[i][0]=='0' && words[i].size()!=1)
                    return "Neither";
                for(int j=0; j<words[i].size(); j++)
                {
                    if(!(words[i][j]>='0' && words[i][j]<='9'))
                        return "Neither";
                }
                if(stoi(words[i])>255)
                    return "Neither";
            }
            return "IPv4";
        }
        if(IP.find(':') != -1)
        {
            vector<string> words;
            string s1 = "";
            IP = IP + ":";
            for(int i=0; i<IP.size(); i++)
            {
                if(IP[i]!=':')
                    s1 += IP[i];
                else
                {
                    words.push_back(s1);
                    s1 = "";
                }
            }
            if(words.size()!=8)
                return "Neither";
            for(int i=0; i<words.size(); i++)
            {
                if(words[i].size()>4 || words[i].size()==0)
                    return "Neither";
                for(int j=0; j<words[i].size(); j++)
                {
                    if((words[i][j]>='a' && words[i][j]<='f') || (words[i][j]>='A' && words[i][j]<='F') || (words[i][j]>='0' && words[i][j]<='9'))
                        continue;
                    return "Neither";
                }
            }
            return "IPv6";
        }
        return "Neither";
    }
};
