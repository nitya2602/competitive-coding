//we need to know the number of 2s and 5s
//number of 5s is less than 2s so we can ignore 2s

class Solution {
public:
    int trailingZeroes(int n) {
        int count = 0;
        for(long int i=5; n/i>=1; i*=5)
        {
            count += n/i;
        }
        return count;
    }
};
