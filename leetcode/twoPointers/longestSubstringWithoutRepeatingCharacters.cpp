class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0, right = 0;
        if(s.size() <= 1)
            return s.size();
        int ans = 0;
        unordered_map<char, int> map;
        while(right < s.size())
        {
            if(map.find(s[right]) == map.end())
            {
                map[s[right]]++;
                right++;
                continue;
            }
            ans = max(ans, right - left);
            while(left < right && s[left] != s[right])
            {
                map.erase(s[left]);
                left++;
            }
            left++;
            right++;
        }
        ans = max(ans, right - left);
        return ans;
    }
};