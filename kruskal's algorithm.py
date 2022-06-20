

class Graph:
    def __init__(self, vertices):
        self.V = vertices
        self.graph = []

    def add_ed(self, a, b, c):
        self.graph.append([a, b, c])

    

    def find(self, parent, p):
        if parent[p] == p:
            return p
        return self.find(parent, parent[p])

    def apply_union(self, parent, rank, u, q):
        uroot = self.find(parent, u)
        qroot = self.find(parent, q)
        if rank[uroot] < rank[qroot]:
            parent[uroot] = qroot
        elif rank[uroot] > rank[qroot]:
            parent[qroot] = uroot
        else:
            parent[qroot] = uroot
            rank[uroot] += 1

   
    def kruskal_algo(self):
        result = []
        p, e = 0, 0
        self.graph = sorted(self.graph, key=lambda item: item[2])
        parent = []
        rank = []
        for node in range(self.V):
            parent.append(node)
            rank.append(0)
        while e < self.V - 1:
            a, b, c = self.graph[p]
            p = p + 1
            u = self.find(parent, a)
            q = self.find(parent, b)
            if u != q:
                e = e + 1
                result.append([a, b, c])
                self.apply_union(parent, rank, u, q)
        for a, b, weight in result:
            print("%d - %d: %d" % (a, b, weight))


g = Graph(6)
g.add_ed(1, 2, 4)
g.add_ed(2, 3, 4)
g.add_ed(5, 1, 1)
g.add_ed(3, 0, 4)
g.add_ed(2, 2, 3)
g.add_ed(0, 2, 4)
g.add_ed(5, 3, 3)
g.add_ed(4, 5, 2)
g.add_ed(2, 4, 3)
g.add_ed(3, 1, 3)
g.add_ed(1, 2, 3)
g.add_ed(5, 2, 1)
g.add_ed(3, 2, 3)
g.add_ed(5, 4, 2)
g.add_ed(5, 4, 1)
g.kruskal_algo()
