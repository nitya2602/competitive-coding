//using bfs to detect cycle in a graph

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> inDegree(numCourses, 0);
        int count=0;
        
        //counting inDegree of all the vertices
        for(int i=0; i<prerequisites.size(); i++)
        {
                inDegree[prerequisites[i][1]]+=1;
        }
        
        //identifying vertices with zero in-degree
        queue<int> aux;
        for(int i=0; i<inDegree.size(); i++)
        {
            if(inDegree[i]==0)
                aux.push(i);
        }
        while(!aux.empty())
        {
            int nm = aux.front();
            aux.pop();
            for(int i=0; i<prerequisites.size(); i++)
            {
                if(prerequisites[i][0]==nm)
                 if(--inDegree[prerequisites[i][1]]==0)
                    aux.push(prerequisites[i][1]);
          
            }
           count++;
        }
        if(count!=numCourses)
            return false;
        return true;
    }
};
