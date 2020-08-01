class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
        int rows = M.size();
        int cols = M[0].size();
        vector<vector<int>> ans(rows, vector<int>(cols, 0));
        for(int r = 0; r<rows; r++)
        {
            for(int c= 0; c<cols; c++)
            {
                int count = 0;
                for(int nr = r-1; nr<= r+1; nr++)
                {
                    for(int nc = c-1; nc <= c+1; nc++)
                    {
                        if(0 <= nr && nr < rows && 0<=nc && nc<cols){
                            ans[r][c] += M[nr][nc];
                            count++;
                        }
                    }
                }
                ans[r][c] /= count;
            }
        }
        return ans;
    }
};
