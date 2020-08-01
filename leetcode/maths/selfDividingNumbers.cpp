class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> res;
        for(int i=left; i<=right; i++)
        {
            int temp = i;
            int count = 0;
            int check = 0;
            while(temp>0)
            {
                count++;
                int a = temp%10;
                if(a!=0 && i%a==0)
                    check++;
                temp /= 10;
            }
            if(count==check)
                res.push_back(i);
            count = 0;
            check = 0;
        }
        return res;
    }
        
};
