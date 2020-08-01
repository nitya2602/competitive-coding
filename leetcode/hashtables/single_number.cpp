//using XOR very nice approach

class Solution {
public:
    int singleNumber(vector<int>& nums) {
      int num;
        for(int i=0; i<nums.size(); i++)
        {
            num^=nums[i];
        }
        return num;
    }
};
