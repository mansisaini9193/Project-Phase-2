
#include <bits/stdc++.h>
using namespace std;


class Graph {
public:
	map<int, bool> visited;
	map<int, list<int> > adj;

	
	void addE(int s, int t);

	
	void DFS(int s);
};

void Graph::addE(int s, int t)
{
	adj[s].push_back(t); 
}

void Graph::DFS(int s)
{
	
	visited[s] = true;
	cout << s << " ";

	
	list<int>::iterator i;
	for (i = adj[s].begin(); i != adj[s].end(); ++i)
		if (!visited[*i])
			DFS(*i);
}


int main()
{
	
	Graph g;
	g.addE(4, 1);
	g.addE(0, 3);
	g.addE(3, 2);
	g.addE(1, 0);
	g.addE(2, 4);
	g.addE(4, 4);

	
	g.DFS(2);

	return 0;
}


