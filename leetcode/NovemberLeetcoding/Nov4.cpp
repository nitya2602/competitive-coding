class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adjList(n);
        vector<int> degree(n, 0);
        //edge cases
        if(n == 1)
            return {0};
        if(n == 2)
            return {0, 1};
        //creating adjacency list and degree count
        for(int i=0; i<edges.size(); i++)
        {
            int src = edges[i][0];
            int dest = edges[i][1];
            adjList[src].push_back(dest);
            adjList[dest].push_back(src);
            degree[src]++;
            degree[dest]++;
        }
        //queue of leaves
        queue<int> q;
        for(int i=0; i<n; i++)
        {
            if(degree[i] == 1)
                q.push(i);
        }
        int vertices = n;
        //moving inwards from leaves
        while(vertices > 2)
        {
            int remove = q.size();
            vertices -= remove;
            for(int i=0; i<remove; i++)
            {
                int top = q.front();
                q.pop();
                //degree maybe negative 
                //we are concerned only about leaves
                //i.e. degree 1
                degree[top]--;
                for(auto j:adjList[top])
                {
                    degree[j]--;
                    if(degree[j] == 1)
                            q.push(j);
                }
            }
        }
        vector<int> ans;
        while(!q.empty())
        {
            ans.push_back(q.front());
            q.pop();
        }
        return ans;
    }
};