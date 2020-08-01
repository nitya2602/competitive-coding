class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int max = *max_element(nums.begin(), nums.end());
        int index;
        for(int i=0; i<nums.size(); i++)
        {
            if(nums[i]==max)
                index = i;
            else
            {
                if(!(max >= 2*nums[i]))
                    return -1;
            }
        }
        return index;
    }
};
