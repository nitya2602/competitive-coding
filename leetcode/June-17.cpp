class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if(board.size()>2)
        {
        
        //replace all O's with -    
        for(int i=0; i<board.size(); i++)
        {
            for(int j=0; j<board[i].size(); j++)
            {
                if(board[i][j]=='O')
                    board[i][j] = '-';
            }
        }
            
        //for corners
            if(board[0][0]=='-')
                board[0][0] = 'O';
            if(board[0][board[0].size()-1]=='-')
                board[0][board[0].size()-1] = 'O';
            if(board[board.size()-1][0]=='-')
                board[board.size()-1][0] = 'O';
            if(board[board.size()-1][board[0].size()-1]=='-')
                board[board.size()-1][board[0].size()-1] = 'O';

        
        //first row
        for(int i=1; i<board[0].size()-1; i++)
        {
            if(board[0][i]=='-')
            {
                board[0][i] = 'O';
                if(board[1][i]=='-')
                    board[1][i] = 'O';
            }
        }
        
        //last row
        for(int i=1; i<board[board.size()-1].size()-1; i++)
        {
            if(board[board.size()-1][i]=='-')
            {
                board[board.size()-1][i] = 'O';
                if(board[board.size()-2][i]=='-')
                    board[board.size()-2][i] = 'O';
            }
        }
        
        //first column
        for(int i=1; i<board.size()-1; i++)
        {
            if(board[i][0]=='-')
            {
                board[i][0] = 'O';
                if(board[i][1]=='-')
                    board[i][1] = 'O';
            }
        }
        
        //last column
        for(int i=1; i<board.size()-1; i++)
        {
            if(board[i][board[i].size()-1]=='-')
            {
                board[i][board[i].size()-1] = 'O';
                if(board[i][board[i].size()-2]=='-')
                    board[i][board[i].size()-2] = 'O';
            }
        }
        
        //replace the remaining -'s with O
        for(int i=0; i<board.size(); i++)
        {
            for(int j=0; j<board[0].size(); j++)
            {
                if(board[i][j]=='-')
                    board[i][j] = 'X';
            }
        }
    }
    }
};
