class Solution {
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        vector<int> distances;
        vector<vector<int>> vertices;
        vertices.push_back(p1);
        vertices.push_back(p2);
        vertices.push_back(p3);
        vertices.push_back(p4);
        
        for(int i = 0; i < 3; i++)
        {
            for(int j = i+1; j < 4; j++)
            {
                int dist = (vertices[i][0] - vertices[j][0])*(vertices[i][0] - vertices[j][0]) + (vertices[i][1] - vertices[j][1])*(vertices[i][1] - vertices[j][1]);
                distances.push_back(dist);
            }
        }
        sort(distances.begin(), distances.end());
        if(distances[0] == distances[4]) return false;
        if(distances[0] == distances[1] && distances[1] == distances[2] && distances[2] == distances[3] && distances[4] == distances[5])
            return true;
        return false;
    }
};