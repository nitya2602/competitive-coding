class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int bill5 = 0, bill10 = 0;
        for(int i=0; i<bills.size(); i++)
        {
            if(bills[i]==5)
                bill5++;
            else if(bills[i]==10)
            {
                bill10++;
                bill5--;
            }
            else
            {
                bill5--;
                if(bill10>0)
                    bill10--;
                else
                    bill5-=2;
            }
            if(bill5<0 || bill10<0)
                return false;
        }
        return true;
    }
};
