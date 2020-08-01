class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> res;
        int i, j = n;
        for(i=0; i<n; i++, j++)
        {
            res.push_back(nums[i]);
            res.push_back(nums[j]);
        }
        return res;
    }
};
