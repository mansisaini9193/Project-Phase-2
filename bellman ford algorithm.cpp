
#include <bits/stdc++.h>
using namespace std;
void BellmanFord(int graph[][3], int R, int H,
				int src)
{
	int dis[R];
	for (int i = 0; i < R; i++)
		dis[i] = INT_MAX;
	dis[src] = 0;
	for (int i = 0; i < R - 1; i++) {

		for (int j = 0; j < H; j++) {
			if (dis[graph[j][0]] != INT_MAX && dis[graph[j][0]] + graph[j][2] <
							dis[graph[j][1]])
				dis[graph[j][1]] =
				dis[graph[j][0]] + graph[j][2];
		}
	}
	for (int i = 0; i < H; i++) {
		int x = graph[i][0];
		int y = graph[i][1];
		int weight = graph[i][2];
		if (dis[x] != INT_MAX &&
				dis[x] + weight < dis[y])
			cout << "Graph contains negative"
					" weight cycle"
				<< endl;
	}

	cout << "Vertex Distance from Source" << endl;
	for (int i = 0; i < R; i++)
		cout << i << "\t\t" << dis[i] << endl;
}
int main()
{
	int R = 5; 
	int H = 8; 

	int graph[][3] = { { 0, 7, -1 }, { 0, 2, 8 },
					{ 1, 6, 3 }, { 1, 3, 2 },
					{ 1, 4, 2 }, { 3, 9, 5 },
					{ 3, 1, 1 }, { 4, 3, -3 } };

	BellmanFord(graph, R, H, 0);
	return 0;
}
