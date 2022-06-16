
#include<bits/stdc++.h>
using namespace std;


class Graph
{
	int M; 

	
	vector<list<int>> adj;
public:
	Graph(int M); 
	
	void addEdge(int m, int w);

	
	void BFS(int s);
};

Graph::Graph(int M)
{
	this->M = M;
	adj.resize(M);
}

void Graph::addEdge(int m, int w)
{
	adj[m].push_back(w); 
}

void Graph::BFS(int s)
{
	
	vector<bool> visited;
	visited.resize(M,false);

	
	list<int> queue;

	
	visited[s] = true;
	queue.push_back(s);

	while(!queue.empty())
	{
		
		s = queue.front();
		cout << s << " ";
		queue.pop_front();

	
		for (auto adjecent: adj[s])
		{
			if (!visited[adjecent])
			{
				visited[adjecent] = true;
				queue.push_back(adjecent);
			}
		}
	}
}


int main()
{
	
	Graph g(4);
	g.addEdge(1, 2);
	g.addEdge(3, 2);
	g.addEdge(2, 1);
	g.addEdge(3, 1);
	g.addEdge(3, 3);
	g.addEdge(1, 3);

	
	g.BFS(2);

	return 0;
}
