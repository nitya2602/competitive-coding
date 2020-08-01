class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n==1)
            return true;
        while(n>3)
        {
            if(n%3!=0)
                return false;
            n = n/3;
        }
        if(n!=3)
            return false;
        return true;
        
        //don't use this method as it may give wrong result due to precision problems
        /*if(n==0)
            return false;
        float a = (float)log(n)/log(3);
        if(a==int(a))
            return true;
        return false;*/
    }
};
