class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int count=0;
        if(nums.size()==0 || k<0)
            return count;
        
        sort(nums.begin(), nums.end());
        if(k==0)
        {
            for(int i=0; i<nums.size()-1; i++)
            {
                int temp = nums[i];
                if(nums[i+1]==temp)
                    count++;
                for(int j=i+1; j<nums.size(); j++)
                {
                    if(nums[j]==temp)
                    {
                        i++;
                    }
                    else
                        break;
                }
            }
        }
        nums.erase(unique(nums.begin(), nums.end()), nums.end());
        for(int i=0; i<nums.size()-1; i++)
        {
            for(int j=i+1; j<nums.size(); j++)
            {
                if(abs(nums[i]-nums[j])==k)
                    count++;
                else if(abs(nums[i]-nums[j])>k)
                    break;
            }
        }
        return count;
    }
};
