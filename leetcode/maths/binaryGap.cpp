class Solution {
public:
    int binaryGap(int N) {
        vector<int> binary;
        while(N>0)
        {
            binary.push_back(N%2);
            N = N/2;
        }
        vector<int> ones;
        for(int i=0; i<binary.size(); i++)
        {
            if(binary[i]==1)
                ones.push_back(i);
        }
        int max = 0;
        for(int i=0; i<ones.size()-1; i++)
        {
            if(ones[i+1]- ones[i]>max)
                max = ones[i+1] - ones[i];
        }
        return max;
    }
};
