class Solution {
public:
    int subtractProductAndSum(int n) {
        int sum = 0;
        int product = 1;
        int temp = n;
        //int aux;
        while(temp>0)
        {
            sum+=temp%10;
            product*=temp%10;
            temp/=10;
        }
        return product - sum;
    }
};
