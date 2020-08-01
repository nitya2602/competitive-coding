class Solution {
public:
    int uniquePaths(int m, int n) {
        int mat[m][n];
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(i==0 || j==0)
                {
                    mat[i][j] = 1;
                    continue;
                }
                mat[i][j] = mat[i-1][j] + mat[i][j-1];
            }
        }
        return mat[m-1][n-1];
    }
};