class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> res;
            int aux = (n%2==0) ? n/2 : (n-1)/2;
            for(int i=1; i<=aux; i++)
            {
                res.push_back(i);
                res.push_back(0-i);
            }
        if(n%2 != 0)
            res.push_back(0);
        return res;
    }
};
