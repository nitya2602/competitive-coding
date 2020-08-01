class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size()/2;
        int count;int ans;
        set<int> s(nums.begin(), nums.end());
        vector<int> v(s.begin(), s.end());
        sort(nums.begin(), nums.end());
        if(nums.size()==1)
            return nums[0];
        for(int i=0; i<v.size(); i++)
        {
            count = 0;
            for(int j=0; j<nums.size(); j++)
            {
                if(v[i]==nums[j])
                {
                    count++;
                }
            }
            if(count>n)
            {
                ans = v[i];
                break;
            }
        }
        return ans;
    }
};
