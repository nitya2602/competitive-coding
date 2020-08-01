//the game is won if the  nummber of stones is not a multiple of 4 

class Solution {
public:
    bool canWinNim(int n) {
        if(n==1 || n==2 || n==3)
            return true;
        if(n%4==0)
            return false;
        return true;
    }
};
