class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        if(nums.size()==3)
            return nums[0]*nums[1]*nums[2];
        int prod1 = nums[0]*nums[1]*nums[nums.size()-1];
        int prod2 = nums[nums.size()-1]*nums[nums.size()-2]*nums[nums.size()-3];
        if(prod1>prod2)
            return prod1;
        return prod2;
    }
};
