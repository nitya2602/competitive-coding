//instead of modifying the original array create a copy even if it affects the space complexity
//avoid modifying the original array

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        vector<int> aux(nums.begin(), nums.end());
        sort(aux.begin(), aux.end());
        aux.erase(unique(aux.begin(), aux.end()), aux.end());
        if(aux.size()<nums.size())
            return true;
        return false;
    }
};
