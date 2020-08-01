class Solution {
public:
    int digitSum(int num) {
        int sum = 0;
        while(num>0)
        {
            sum += num%10;
            num /= 10;
        }
        return sum;
    }
    
    int countLargestGroup(int n) {
        map<int, int> m;
         
        for(int i=1; i<=n; i++)
        {
            int temp = digitSum(i);
            /*if(m.find(temp) == m.end())
                m.insert(temp, 1);
            else
                m[temp]++;*/
            m[temp]++;
        }
        
        int max = 0;
        int count = 0;
        for(auto i=m.begin(); i!=m.end(); i++)
        {
            if(i->second == max)
                count++;
            if(i->second > max)
            {
                max = i->second;
                count = 1;
            }
        }
        return count;
    }
};
