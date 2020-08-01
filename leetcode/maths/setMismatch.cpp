class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        vector<int> aux(n+1, 0);
        vector<int> res;
        sort(nums.begin(), nums.end());
        for(int i=0; i<n; i++)
        {
            aux[nums[i]] = 1;
            if(i!=n-1 && nums[i]==nums[i+1])
            {
                res.push_back(nums[i]);
            }
        }
        for(int i=1; i<=n; i++)
        {
            if(aux[i]==0)
            {
                res.push_back(i);
                break;
            }
        }
        return res;
    }
};
