//it is not the correct solution

class Solution {
public:
    string longestPalindrome(string s) {
        int length=0;
        string ans;
        vector<char> array(s.begin(), s.end());
        for(int i=0; i<s.length(); i++)
        {
            int temp = length;
            length = 0;
            int m,n;
            char ch = array[i];
            m=i;
            int j;
            for(j=array.size()-1; j>=i; j--)
            {
                if(array[j]==ch)
                {
                    length+=2;
                    n=j;
                    break;
                }
            }
            if(m==n)
            {
                length = 1;
                if(length>temp)
                    ans = s[m];
            }
            //m-=1;
            //n+=1;
            while(m<n && m!=n-1 && array[m++]==array[n--])
            {
                if(m==n)
                    length-=1;

                length+=2;
                                /*m++;
                n--;
                if(m>=1001)
                    break;
                if(n<=0)
                    break;*/
            }
           if(length>temp)
               ans = s.substr(i, length);
        }
        return ans;
    }
};
