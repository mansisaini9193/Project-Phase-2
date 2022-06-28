
class DisjointSet:
    parent = {}
    def makeSet(self, universe):
        for i in universe:
            self.parent[i] = i
    def Find(self, k):
        if self.parent[k] == k:
            return k
        return self.Find(self.parent[k])
    def Union(self, a, b):
        x = self.Find(a)
        y = self.Find(b)
        self.parent[x] = y
def printSets(universe, ds):
    print([ds.Find(i) for i in universe])
if __name__ == '__main__':
    universe = [1,2,3,4,5]
    ds = DisjointSet()
    ds.makeSet(universe)
    printSets(universe, ds)
    ds.Union(4, 3) 
    printSets(universe, ds)
    ds.Union(2, 1) 
    printSets(universe, ds)
    ds.Union(1, 3) 
    printSets(universe, ds)
 
