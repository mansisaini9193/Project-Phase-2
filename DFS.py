
from collections import defaultdict




class Graph:

	
	
	def __init__(self):

		
		self.graph = defaultdict(list)

	def addEdge(self, r, j):
		self.graph[r].append(j)


	def DFSUtil(self, j, visited):

		
		visited.add(j)
		print(j, end=' ')

		
		for neighbour in self.graph[j]:
			if neighbour not in visited:
				self.DFSUtil(neighbour, visited)

	
	def DFS(self, j):

		
		visited = set()

		
		self.DFSUtil(j, visited)


g = Graph()
g.addEdge(4, 1)
g.addEdge(3, 2)
g.addEdge(1, 1)
g.addEdge(4, 0)
g.addEdge(2, 4)
g.addEdge(3, 3)

print("Following is DFS from (starting from vertex 2)")
g.DFS(2)

