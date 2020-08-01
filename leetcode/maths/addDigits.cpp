// for base d, if num%(d-1)==0 return d-1
// else return num%9
// for num==0 return 0

class Solution {
public:
    int addDigits(int num) {
        if(num==0)
            return 0;
        if(num%9 == 0)
            return 9;
        return num%9;
    }
};
