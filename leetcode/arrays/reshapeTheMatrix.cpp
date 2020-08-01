// see how to initialize a nested vector with size

class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        int rn = nums.size();
        int cn = nums[0].size();
        int size = rn*cn;
        if(size!=r*c)
            return nums;
        vector<vector<int>> reshape(r, vector<int>(c));
        deque<int> aux1;
        for(int i=0; i<rn; i++)
        {
            for(int j=0; j<cn; j++)
            {
                aux1.push_back(nums[i][j]);
            }
        }
        for(int i=0; i<r; i++)
        {
            for(int j=0; j<c; j++)
            {
                reshape[i][j] = aux1.front();
                aux1.pop_front();
            }
        }
        return reshape;
    }
};
