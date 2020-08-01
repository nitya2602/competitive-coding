//this approach is better than th brute force approach
//using vectors consumes less space than maps 

class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> count(101, 0);
        for(int num: nums)
        {
            count[num]++;
        }
        int total = 0;
        for(int i=0; i<101; i++)
        {
            if(count[i]!=0)
            {
                int temp = count[i];
                count[i] = total;
                total+=temp;
            }
        }
        for(int i=0; i<nums.size(); i++)
        {
            nums[i] = count[nums[i]];
        }
        return nums;
    }
};
