class Solution {
public:
    int totalFruit(vector<int>& tree) {
        int type1 = -1, type2 = -1;
        int left = 0, right = left+1;
        if(tree.size() <= 2) 
            return tree.size();
        type1 = tree[left];
        int ans = 0;
        while(left <= right && right < tree.size())
        {
            while(right < tree.size() && (tree[right] == type1 || tree[right] == type2))
                right++;
            if(right == tree.size())
            {
                ans = max(ans, right - left);
                return ans;
            }
            if(type2 == -1)
            {
                type2 = tree[right];
                continue;
            }
            ans = max(ans, right - left);
            left = left + 1;
            right = left + 1;
            type1 = tree[left];
            type2 = -1;
        }
        return ans;
    }
};