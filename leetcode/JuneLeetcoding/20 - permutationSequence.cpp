class Solution {
public:
    string getPermutation(int n, int k) {
        int num = 0;
        for(int i=1; i<=n; i++)
            num = num*10 + i;
        string str = to_string(num);
        
        //not k-- as we are getting next permutation so we need to 
        //stop one step earlier
        while(--k)
            next_permutation(str.begin(), str.end());
        return str;
    }
};
