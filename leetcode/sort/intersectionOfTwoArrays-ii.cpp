class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;
        unordered_map<int, int> mapObj;
        for(const auto&number : nums1)
            mapObj[number]++;
        for(const auto&number : nums2)
        {
            mapObj[number]--;
            if(mapObj[number]>=0)
                result.push_back(number);
        }
        return result;
    }
};
