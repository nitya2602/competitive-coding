class Solution {
public:
    double calculate(double x, int n)
    {
        if(n == 1 || n == -1)
            return x;
        //without using temp we get TLE
        double temp = calculate(x, n/2);
        if(n % 2 == 0)
            return temp*temp;
        return x*temp*temp;
    }
    
    double myPow(double x, int n) {
        double ans;
        if(x == 1 || n == 0)
            return 1;
        if(x == -1)
        {
            if(n % 2 == 0)
                return 1;
            return -1;
        }
        if(n < 0)
            x = 1/x;
        ans = calculate(x, n);
        return ans;
    }
};