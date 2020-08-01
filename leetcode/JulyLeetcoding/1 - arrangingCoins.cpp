class Solution {
public:
    int arrangeCoins(int n) {
        long sum = 0;
        int count = 0;
        int i=1;
        while(sum+i<=n)
        {
            count++;
            sum += i;
            i++;
        }
        return count;
    }
};
