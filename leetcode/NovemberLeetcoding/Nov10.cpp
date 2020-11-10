class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        for(int i = 0; i < A.size(); i++)
        {
            int left = 0;
            int right = A[i].size() - 1;
            while(left < right)
            {
                int temp = A[i][left];
                A[i][left] = 1 - A[i][right];
                A[i][right] = 1 - temp;
                left++;
                right--;
            }
            if(left == right)
                A[i][left] = 1 - A[i][left];
        }
        return A;
    }
};