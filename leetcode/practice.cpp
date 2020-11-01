#include<bits/stdc++.h>
using namespace std;

struct  Edge{
	int src, dest;
};

class Graph{
	public:
		vector<vector<int>> adjList;
		Graph(vector<Edge> const &edges, int N)
		{
			adjList.resize(N);
			for(auto &edge: edges)
				adjList[edge.src].push_back(edge.dest);
		}
};

void DFS(Graph const &graph, int v, vector<bool> discovered, vector<int> &arrival, vector<int> &departure, int &time)
{
	arrival[v] = ++time;
	discovered[v] = true;
	for(int i:graph.adjList[v])
	{
		if(!discovered[i])
		{
			DFS(graph, i, discovered, arrival, departure);
		}
	}
	departure[v] = ++time;
}

int main()
{
	vector<Edge> edges = {
	{0,1},{0,2},{2,3},{2,4},{3,1},{3,5},{4,5},{6,7}
	};
	int N = 8;
	Graph graph(edges, N);
	vector<int> arrival(N);
	vector<int> departure(N);
	vector<bool> discovered(N);
	int time = -1;
	for(int i=0; i<N; i++)
	{
		if(!discovered[i])
		{
			DFS(graph, i, discovered, arrival, departure, time);
		}
	}
	for(int i=0; i<N; i++)
	{
		cout<<"Vertex "<<i<<" ("<<arrival[i]<<", "<<departure[i]<<")"<<endl;
	}
	return 0;
}
