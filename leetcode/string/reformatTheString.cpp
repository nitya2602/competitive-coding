class Solution {
public:
    string reformat(string s) {
        int alpha, nums;
        alpha = nums = 0;
        vector<char> a;
        vector<char> n;
        for(int i=0; i<s.size(); i++)
        {
            if(s[i]>='a' && s[i]<='z')
            {
                alpha++;
                a.push_back(s[i]);
            }
            else
            {
                nums++;
                n.push_back(s[i]);
            }
        }
        if(!(alpha-nums==0 || alpha-nums==1 || alpha-nums==-1))
            return "";
        int j=0, k=0;
        string ans = "";
        if(alpha>nums)
        {
            while(j<alpha && k<nums)
            {
                ans+=a[j++];
                ans+=n[k++];
            }
            ans+=a[j];
        }
        else if(nums>alpha)
        {
           while(k<nums && j<alpha)
            {
                ans+=n[k++];
                ans+=a[j++];
            } 
            ans+=n[k];
        }
        else
        {
          while(k<nums && j<alpha)
            {
                ans+=n[k++];
                ans+=a[j++];
            }   
        }
        return ans;
    }
};
