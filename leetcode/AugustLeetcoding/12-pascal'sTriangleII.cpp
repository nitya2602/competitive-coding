class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ans, temp;
        ans.push_back(1);
        if(rowIndex==0)
            return ans;
        for(int i=1; i<=rowIndex; i++)
        {
            temp.clear();
            temp.push_back(1);
            for(int j=1; j<i; j++)
            {
                temp.push_back(ans[j] + ans[j-1]);
            }
            temp.push_back(1);
            ans = temp;
        }
        return ans;
    }
};
