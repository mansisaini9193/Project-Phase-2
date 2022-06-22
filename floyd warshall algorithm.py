
Y = 4
INF = 99999
def floydWarshall(g):
	dst = list(map(lambda h: list(map(lambda g: g, h)), g))
	for e in range(Y):
		for h in range(Y):
			for g in range(Y):
				dst[h][g] = min(dst[h][g],
								dst[h][e] + dst[e][g]
								)
	printSol(dst)
def printSol(dst):
	print ("Following matrix shows the shortest distances\
between every pair of vertices")
	for h in range(Y):
		for g in range(Y):
			if(dst[h][g] == INF):
				print ("%7s" % ("INF"),end=" ")
			else:
				print ("%7d\t" % (dst[h][g]),end=' ')
			if g == Y-1:
				print ()
g = [[8, 1, INF, 40],
		[INF, 34, 2, INF],
		[INF, INF, 9, 22],
		[INF, INF, INF, 5]
		]
floydWarshall(g)

