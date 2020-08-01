//we need to add 1 while finding number of bits in binary representation of num
//if we use ceiling function, it doesn't work for powers of 2

class Solution {
public:
    int bitwiseComplement(int N) {
        if(N==0)
            return 1;
        int p = int(log(N)/log(2)) + 1;
        return pow(2, p) - N - 1;
    }
};
