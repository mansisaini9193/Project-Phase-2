
#include <iostream>
using namespace std;
#include <limits.h>
#define K 9
int minDistance(int dis[], bool sptSet[])
{
	int min = INT_MAX, min_index;

	for (int k = 0; k < K; k++)
		if (sptSet[k] == false && dis[k] <= min)
			min = dis[k], min_index = k;

	return min_index;
}
void printS(int dis[])
{
	cout <<"Vertex \t Distance from Source" << endl;
	for (int c = 0; c < K; c++)
		cout << c << " \t\t"<<dis[c]<< endl;
}
void dijkstra(int graph[K][K], int src)
{
	int dis[K]; 
	bool sptSet[K];
	for (int c = 0; c < K; c++)
		dis[c] = INT_MAX, sptSet[c] = false;
	dis[src] = 0;
	for (int count = 0; count < K - 1; count++) {
		int u = minDistance(dis, sptSet);
		sptSet[u] = true;
		for (int k = 0; k < K; k++)
			if (!sptSet[k] && graph[u][k] && dis[u] != INT_MAX
				&& dis[u] + graph[u][k] < dis[k])
				dis[k] = dis[u] + graph[u][k];
	}
	printS(dis);
}
int main()
{
	int graph[K][K] = { { 1, 4, 0, 9, 0, 10, 15, 8, 2 },
						{ 4, 5, 8, 0, 5, 4, 0, 11, 0 },
						{ 0, 8, 0, 14, 7, 4, 2,8, 2 },
						{ 0, 99, 7, 0, 6, 14, 0, 0, 0 },
						{ 0, 0, 0, 9, 0, 10, 0, 24, 23 },
						{ 0, 22, 4, 14, 10, 17, 2, 0, 66 },
						{ 0, 0, 0, 44, 0, 88, 0, 1, 6 },
						{ 8, 11, 0, 0, 0, 33, 1, 0, 7 },
						{ 0, 0, 78, 0, 0, 0, 12, 7, 0 } };

	dijkstra(graph, 0);

	return 0;
}


