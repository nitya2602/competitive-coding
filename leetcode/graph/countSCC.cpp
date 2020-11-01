#include<bits/stdc++.h>
using namespace std;

struct Edge{
    int src, dest;
};

class Graph{
    public:
    vector<vector<int>> adjList;
    Graph(vector<Edge> const &edges, int N)
    {
        adjList.resize(N);
        for(Edge const &edge: edges)
        {
            adjList[edge.src].push_back(edge.dest);
        }
    }
};

void DFS(Graph const &graph, int src, vector<bool> &visited)
{
    visited[src] = true;
    for(auto i: graph.adjList[src])
    {
        if(!visited[i])
            DFS(graph, i, visited);
    }
}

Graph getTranspose(Graph const &graph, int N)
{
    vector<Edge> edges;
    for(int i=0; i<N; i++)
    {
        for(auto u: graph.adjList[i])
        {
            edges.push_back({u, i});
        }
    }
    Graph g(edges, N);
    return g;
}

void fillOrder(Graph const &graph, int src, vector<bool> &visited, stack<int> &Stack)
{
    visited[src] = true;
    for(auto u: graph.adjList[src])
    {
        if(!visited[u])
            fillOrder(graph, u, visited, Stack);
    }
    Stack.push(src);
}

int countSCC(Graph const &graph, int N)
{
    stack<int> Stack;
    vector<bool> visited(N, false);
    for(int i=0; i<N; i++)
    {
        if(!visited[i])
            fillOrder(graph, i, visited, Stack);
    }
    Graph gr = getTranspose(graph, N);
    for(int i=0; i<N; i++)
        visited[i] = false;
    int count  = 0;
    while(!Stack.empty())
    {
        int v = Stack.top();
        Stack.pop();
        if(visited[v])
            continue;
        if(!visited[v])
            DFS(gr, v, visited);
        count++;
    }
    return count;
}

int main()
{
    vector<Edge> edges = {
        {1,0},{0,2},{2,1},{0,3},{3,4}
    };
    int N = 5;
    Graph graph(edges, N);
    cout<<countSCC(graph, N);
    return 0;
}
