class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i = 0; i < 9; i++)
        {
            vector<int> map(10, 0);
            for(int j = 0; j < 9; j++)
            {
                if(board[i][j] != '.')
                {
                    int idx = board[i][j] - '0';
                    map[idx]++;
                    if(map[idx] > 1)
                        return false;
                }
            }
        }
        for(int i = 0; i < 9; i++)
        {
            vector<int> map(10, 0);
            for(int j = 0; j < 9; j++)
            {
                if(board[j][i] != '.')
                {
                    int idx = board[j][i] - '0';
                    map[idx]++;
                    if(map[idx] > 1)
                        return false;
                }
            }
        }
        for(int i = 0; i < 9; i += 3)
        {
            for(int j = 0; j < 9; j += 3)
            {
                vector<int> map(10, 0);
                for(int m = i; m <= i + 2; m++)
                {
                    for(int n = j; n <= j + 2; n++)
                    {
                        if(board[m][n] != '.')
                        {
                            int idx = board[m][n] - '0';
                            cout<<idx<<" ";
                            map[idx]++;
                            if(map[idx] > 1)
                                return false;
                        }
                    }
                }
            }
        }
        return true;
    }
};