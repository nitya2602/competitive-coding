//do it on the basis of odd and even parity

class Solution {
public:
    int minCostToMoveChips(vector<int>& chips) {
        int odd = 0;
        int even = 0;
        for(int i=0; i<chips.size(); i++)
        {
            if(chips[i]%2==0)
                even++;
            else
                odd++;
        }
        if(even==chips.size()|| odd==chips.size())
            return 0;
        return min(odd, even);
    }
};
