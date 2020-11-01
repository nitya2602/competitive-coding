class Solution {
public:
    bool isPowerOfFour(int num) {
        if(num<=0)
            return false;
        if(num==1)
            return true;
        int flag = 0;
        while(num>0)
        {
            if(num%4!=0 && num!=1)
            {
                flag = 1;
                break;
            }
            num = num/4;
        }
        if(flag==0)
            return true;
        return false;
    }
};
