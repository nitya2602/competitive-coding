class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        if(nums.size()==0)
            return nums;
        sort(nums.begin(), nums.end());
        vector<int> divCount(nums.size(), 1);
        vector<int> prev(nums.size(), -1);
        vector<int> res;
        int max_index = 0;
        for(int i=1; i<nums.size(); i++)
        {
            for(int j=0; j<i; j++)
            {
                if(nums[i]%nums[j]==0)
                {
                    if(divCount[i] < divCount[j]+1)
                    {
                        divCount[i] = divCount[j] + 1;
                        prev[i] = j;
                    }
                }
                if(divCount[max_index] < divCount[i])
                    max_index = i;
            }
        }
        while(max_index>=0)
        {
            res.push_back(nums[max_index]);
            max_index = prev[max_index];
        }
        sort(res.begin(), res.end());
        return res;
    }
};
