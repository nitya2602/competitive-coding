class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        vector<int> sums;
        int sum = 0;
        if(nums.size()==0)
            return -1;
        for(int i=0; i<nums.size(); i++)
        {
            sum+=nums[i];
            sums.push_back(sum);
        }
        if(sums[sums.size()-1]-nums[0]==0)
            return 0;
        for(int i=1; i<nums.size()-1; i++)
        {
            if(sums[i-1]==sums[sums.size()-1]-sums[i])
                return i;
        }
        if(sums[sums.size()-2]==0)
            return nums.size()-1;
        return -1;
    }
};
