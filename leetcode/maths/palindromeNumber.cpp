class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0)
            return false;
        if(x>=0 && x<=9)
            return true;
        if(x%10==0)
            return false;
        int reverse = 0;
        while(reverse < x)
        {
            reverse = reverse*10 + x%10;
            x = x/10;
        }
        
        //x==reverse/10 i required when x has odd number of digits like in 121
        if(x == reverse || x==reverse/10)
            return true;
        return false;
    }
};
