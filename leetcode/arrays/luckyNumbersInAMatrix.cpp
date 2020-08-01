class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        vector<int> res;
        vector<int> rows;
        vector<int> col;
        for(int i=0; i<matrix.size(); i++)
        {
            rows.push_back(*min_element(matrix[i].begin(), matrix[i].end()));
        }
        for(int i=0; i<matrix[0].size(); i++)
        {
            int max= 0;
            for(int j=0; j<matrix.size(); j++)
            {
                if(matrix[j][i]>max)
                    max = matrix[j][i];
            }
            col.push_back(max);
        }
        for(int i=0; i<matrix.size(); i++)
        {
            for(int j=0; j<matrix[0].size(); j++)
            {
                if(matrix[i][j]==rows[i] && matrix[i][j]==col[j])
                    res.push_back(matrix[i][j]);
            }
        }
        return res;
    }
};
