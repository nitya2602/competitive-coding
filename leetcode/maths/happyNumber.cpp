//check until number reduces to a single digit number
//amongst single digit number it is a happy number only for 1 and 7

class Solution {
public:
    bool isHappy(int n) {
        if(n==1 || n==7)
            return true;
        int temp = n;
        while(!(temp>=1 && temp<=9))
        {
            int m = temp;
            temp = 0;
            vector<int> aux;
            while(m>0)
            {
                aux.push_back(m%10);
                m = m/10;
            }
            for(int i=0; i<aux.size(); i++)
            {
                temp+=aux[i]*aux[i];
            }
            if(temp==1 || temp==7)
                return true;
        }
        return false;
    }
};
