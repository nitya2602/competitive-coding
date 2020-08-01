// 100% faster and 100% less space consumed

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> pascal;
        if(numRows==0)
            return pascal;

        vector<int> a;
        a.push_back(1);
        pascal.push_back(a);
        if(numRows==1)
            return pascal;

        a.push_back(1);
        pascal.push_back(a);
        if(numRows==2)
            return pascal;

        for(int i=2; i<numRows; i++)
        {
            vector<int> aux;
            aux.push_back(1);
            for(int j=0; j<pascal[i-1].size()-1; j++)
            {
                aux.push_back(pascal[i-1][j]+pascal[i-1][j+1]);
            }
            aux.push_back(1);
            pascal.push_back(aux);
        }
        return pascal;
    }
};
