class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        digits[digits.size()-1]+=1;
        int num;
        for(int i=digits.size()-1; i>0; i--)
        {
            num = digits[i];
            if(digits[i]>9)
            {
                digits[i] = num%10;
                digits[i-1] += num/10;
            }
        }
        deque<int> dig(digits.begin(), digits.end());
        if(digits[0]>9)
        {
            int a = digits[0];
            dig[0] = a%10;
            a = a/10;
            dig.push_front(a);
        }
        vector<int> abc(dig.begin(), dig.end());
        return abc;
    }
};
