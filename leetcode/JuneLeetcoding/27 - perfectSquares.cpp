class Solution {
public:
    int numSquares(int n) {
        vector<int> sq;
        int x = 1;
        while(x*x <= n)
        {
            sq.push_back(x*x);
            x++;
        }
        for(int i=0; i<sq.size(); i++)
        {
            if(sq[i]==n)
                return 1;
        }
        
        for(int i=0; i<sq.size(); i++)
        {
            for(int j=0; j<sq.size(); j++)
            {
                if(sq[i] + sq[j] == n)
                    return 2;
            }
        }
        
        for(int i=0; i<sq.size(); i++)
        {
            for(int j=0; j<sq.size(); j++)
            {
                for(int k=0; k<sq.size(); k++)
                {
                    if(sq[i]+sq[j]+sq[k]==n)
                        return 3;
                }
            }
        }
        return 4;
    }
};
