class Solution {
public:
    void helper(int num, int &even,int &odd)
    {
        if(num==0)
            return;
        if(num%2==0)
        {
            even++;
            helper(num/2, even, odd);
        }
        else
        {
            odd++;
            helper(num-1, even, odd);
        }
    }
    int numberOfSteps (int num) {
        if(num==0)
            return 0;
        int odd=0;
        int even=0;
        helper(num, even, odd);
        return even+odd;
    }
};
