//sliding window approach

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double sum=0, max=-10000000;
        if(nums.size()==k)
            return accumulate(nums.begin(), nums.end(), 0)/double(k);
        for(int i=0; i<k; i++)
            sum+=nums[i];
        max = sum;
        for(int i=1; i<nums.size()-k+1; i++)
        {
            sum -= nums[i-1];
            sum += nums[i-1+k];
            if(sum>max)
                max = sum;
        }
        return max/k;
    }
};
