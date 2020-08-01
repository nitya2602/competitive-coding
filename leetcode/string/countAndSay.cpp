class Solution {
public:
    string countAndSay(int n) {
        string ans = "";
        string temp = "11";
        if(n==1)
            return "1";
        if(n==2)
            return temp;
        for(int i=3; i<=n; i++)
        {
            int count = 1;
            int flag = 0;
            char aux;
            for(int j=0; j<temp.size()-1; j++)
            {
                if(temp[j]==temp[j+1])
                {
                    count++;
                    flag = 0;
                    aux = temp[j];
                }
                else
                {
                    ans += to_string(count);
                    count = 1;
                    ans += temp[j];
                    flag = 1;
                }
            }
            if(flag==0)
            {
                ans += to_string(count);
                ans += aux;
            }
            if(temp[temp.size()-1]!=temp[temp.size()-2])
            {
                ans += "1";
                ans += temp[temp.size()-1];
            }
            temp = ans;
            ans = "";
        }
        ans = temp;
        return ans;
    }
};
