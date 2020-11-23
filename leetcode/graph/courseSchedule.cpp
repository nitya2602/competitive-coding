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
            if(inDegree[i] == 0)
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


//using topologicalSort to detect cycle in a graph

class Solution {
public:
    void DFS(unordered_map<int, vector<int>>& adj, int u, vector<bool> &visited, vector<int> &departure, int &t)
    {
        visited[u] = true;
        for(int v : adj[u])
        {
            if(!visited[v])
            {
                DFS(adj, v, visited, departure, t);
            }
        }
        departure[++t] = u;
        cout<<u<<endl;
    }
    
    vector<int> topologicalSort(unordered_map<int, vector<int>> &adj, int numCourses)
    {
        vector<bool> visited(numCourses, false);
        vector<int> departure(2*numCourses+1, -1);
        int t = 0;
        vector<int> ans;
        for(int i = 0; i < numCourses; i++)
        {
            if(!visited[i])
            {
                DFS(adj, i, visited, departure, t);
            }
        }
        for(int i = departure.size()-1; i >= 0; i--)
        {
            if(departure[i] != -1)
                ans.push_back(departure[i]);
        }
        return ans;
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> adj;
        
        //creating graph
        for(int i = 0; i < prerequisites.size(); i++)
        {
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }

        vector<int> sort = topologicalSort(adj, numCourses);
        unordered_map<int, int> index;
        int ind = 0;
        for(int i = 0; i < sort.size(); i++)
        {
            index[sort[i]] = ind;
            ind++;
        }
        
        for(int i = 0; i < prerequisites.size(); i++)
        {
            if(index[prerequisites[i][0]] < index[prerequisites[i][1]])
                return false;
        }
        return true;
    }
};