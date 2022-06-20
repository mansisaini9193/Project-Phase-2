
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

#define edge pair<int, int>

class Graph {
   private:
  vector<pair<int, edge> > G;  
  vector<pair<int, edge> > T;  
  int *parent;
  int V;  
   public:
  Graph(int V);
  void AddWE(int u, int v, int w);
  int find_set(int i);
  void union_set(int u, int v);
  void kruskal();
  void print();
};
Graph::Graph(int V) {
  parent = new int[V];

  
  for (int i = 0; i < V; i++)
    parent[i] = i;

  G.clear();
  T.clear();
}
void Graph::AddWE(int s, int e, int m) {
  G.push_back(make_pair(m, edge(s, e)));
}
int Graph::find_set(int h) {
  
  if (h == parent[h])
    return h;
  else
    
    return find_set(parent[h]);
}

void Graph::union_set(int s, int e) {
  parent[s] = parent[e];
}
void Graph::kruskal() {
  int n, uRep, vRep;
  sort(G.begin(), G.end());  
  for (n = 0; n < G.size(); n++) {
    uRep = find_set(G[n].second.first);
    vRep = find_set(G[n].second.second);
    if (uRep != vRep) {
      T.push_back(G[n]);  
      union_set(uRep, vRep);
    }
  }
}
void Graph::print() {
  cout << "E :"
     << " W" << endl;
  for (int a= 0; a < T.size(); a++) {
    cout << T[a].second.first << " - " << T[a].second.second << " : "
       << T[a].first;
    cout << endl;
  }
}
int main() {
  Graph g(6);
  g.AddWE(1, 1, 4);
  g.AddWE(0, 3, 2);
  g.AddWE(1, 5, 2);
  g.AddWE(2, 0, 4);
  g.AddWE(2, 0, 3);
  g.AddWE(2, 1, 3);
  g.AddWE(3, 3, 3);
  g.AddWE(1, 5, 4);
  g.AddWE(1, 4, 4);
  g.AddWE(3, 5, 3);
  g.AddWE(1, 4, 3);
  g.AddWE(4, 2, 5);
  g.AddWE(5, 3, 2);
  g.AddWE(5, 2, 1);
  g.AddWE(2, 4, 3);
  g.kruskal();
  g.print();
  return 0;
}
