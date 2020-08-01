class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int count=1, max=1;
        if(nums.size()==0)
            return 0;
        if(nums.size()==1)
            return 1;
        for(int i=1; i<nums.size(); i+=count)
        {
            count = 1;
            for(int j=i; j<nums.size(); j++)
            {
                if(nums[j]>nums[j-1])
                    count++;
                else
                    break;
            }
            if(count>max)
                max = count;
        }
        return max;
    }
};
