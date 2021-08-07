class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int l = 0, r = nums.size()-1;
        int mid;
        while(l < r)
        {
            mid = (l + r)/2;
            int leq = 0, geq = 0;
            for(int i = 0; i < nums.size(); i++)
            {
                if(nums[i] >= mid)
                    geq++;
                if(nums[i] <= mid)
                    leq++;
            }
            if(leq > mid)
                r = mid;
            if(geq > nums.size()-mid)
                l = mid;
            if(l == r)
                return l;
            if(l == mid)
                l++;
            else r--;
        }
        return l;
    }
};