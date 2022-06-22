
#include <bits/stdc++.h>
using namespace std;


#define D 4


#define INF 99999


void printS(int dist[][D]);


void floydWarshall(int graph[][D])
{
	
	int dist[D][D], p, q, r;

	
	for (p = 0; p < D; p++)
		for (q = 0; q < D; q++)
			dist[p][q] = graph[p][q];

	

	for (r = 0; r < D; r++) {
		
		for (p = 0; p < D; p++) {
			
			for (q = 0; q < D; q++) {
				
				if (dist[p][q] > (dist[p][r] + dist[r][q])
					&& (dist[r][q] != INF
						&& dist[p][r] != INF))
					dist[p][q] = dist[p][r] + dist[r][q];
			}
		}
	}


	printS(dist);
}


void printS(int dist[][D])
{
	
	for (int p = 0; p < D; p++) {
		for (int q = 0; q < D; q++) {
			if (dist[p][q] == INF)
				cout << "INF"
					<< "	 ";
			else
				cout << dist[p][q] << "	 ";
		}
		cout << endl;
	}
}


int main()
{
	
	int graph[D][D] = { { 7, 4, INF, 20 },
						{ INF, 1, 9, INF },
						{ INF, INF, 0, 3 },
						{ INF, INF, INF, 6 } };

	
	floydWarshall(graph);
	return 0;
}


