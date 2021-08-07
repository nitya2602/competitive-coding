//revise this question Q15 leetcode

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        if(nums.size() < 3)
            return ans;
        if(nums.size() == 3 && (nums[0] + nums[1] + nums[2]) == 0)
        {
            ans.push_back(nums);
            return ans;
        }
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size()-2; i++)
        {
            if(nums[i] == 0 && nums[i] == nums[i+1] && nums[i+1] == nums[i+2])
            {
                ans.push_back({0,0,0});
                break;
            }
            if(nums[i] > 0)
                break;
            if(i > 0 && nums[i] == nums[i-1])
                continue;
            int j = i + 1;
            int k = nums.size()-1;
            int target = 0 - nums[i];
            while(j < k)
            {
                if(nums[j] + nums[k] == target)
                {
                    ans.push_back({nums[i], nums[j], nums[k]});
                    j++;
                    k--;
                    while(j < k && nums[j] == nums[j-1])
                        j++;
                    while(j < k && k+1 < nums.size() && nums[k] == nums[k+1])
                        k--;
                }
                else if(nums[j]+nums[k] > target)
                    k--;
                else j++;
            }
        }
        return ans;
    }
};

//-5 -5 -4 -4 -4 -2 -2 -2 0 0 0 1 1 3 4 4 
//-4 -1 -1 0 1 2