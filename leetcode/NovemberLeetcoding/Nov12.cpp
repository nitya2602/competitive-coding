class Solution {
public:
    void permute(vector<int> &nums, int left, int right, vector<vector<int>> &ans)
    {
        if(left == right)
            ans.push_back(nums);
        for(int i = left; i <= right; i++)
        {
            unordered_map<int, int> map;
            for(int j = left; j < i; j++)
            {
                map[nums[j]] = j;
            }
            if(map.find(nums[i]) == map.end())
            {
                swap(nums[i], nums[left]);
                permute(nums, left+1, right, ans);
                swap(nums[i], nums[left]);
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        permute(nums, 0, nums.size()-1, ans);
        return ans;
    }
};