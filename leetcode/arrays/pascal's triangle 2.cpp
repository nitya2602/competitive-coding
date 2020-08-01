//100% less space and faster than 19.15%
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        int numRows = rowIndex+1;
        vector<vector<int>> pascal;
        if(numRows==0)
            return vector<int>();

        vector<int> a;
        a.push_back(1);
        pascal.push_back(a);
        if(numRows==1)
            return pascal[0];

        a.push_back(1);
        pascal.push_back(a);
        if(numRows==2)
            return pascal[1];

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
        return pascal[rowIndex];
    }
};
    
