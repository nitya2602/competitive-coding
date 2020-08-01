class Solution {
public:
    int MAX = pow(2,31)-1;
    int MIN = -pow(2,31);
    int reverse(int x) {
        int ans = 0;
        while(x!=0)   //x can be negative also so while(x>0) won't work
        {
            int digit = x%10;
            x = x/10;
            if(ans > MAX/10 || ans==MAX/10 && digit>7)
                return 0;
            if(ans < MIN/10 || ans==MIN/10 && digit<-8)
                return 0;
            ans = ans*10 + digit;
        }
        return ans;
    }
};
