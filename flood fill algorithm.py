
def isValid(screen, m, n, x, y, prevC, newC):
	if x<0 or x>= m\
	or y<0 or y>= n or\
	screen[x][y]!= prevC\
	or screen[x][y]== newC:
		return False
	return True
def floodFill(screen,
			m, n, x,
			y, prevC, newC):
	queue = []
	queue.append([x, y])
	screen[x][y] = newC
	while queue:
		currPixel = queue.pop()
		posX = currPixel[0]
		posY = currPixel[1]
		if isValid(screen, m, n,
				posX + 1, posY,
						prevC, newC):
			screen[posX + 1][posY] = newC
			queue.append([posX + 1, posY])
		
		if isValid(screen, m, n,
					posX-1, posY,
						prevC, newC):
			screen[posX-1][posY]= newC
			queue.append([posX-1, posY])
		
		if isValid(screen, m, n,
				posX, posY + 1,
						prevC, newC):
			screen[posX][posY + 1]= newC
			queue.append([posX, posY + 1])
		
		if isValid(screen, m, n,
					posX, posY-1,
						prevC, newC):
			screen[posX][posY-1]= newC
			queue.append([posX, posY-1])
screen =[
[1, 1, 1, 1, 1, 1, 1, 1],
[1, 1, 1, 1, 1, 1, 0, 0],
[1, 0, 0, 1, 1, 0, 1, 1],
[1, 2, 2, 2, 2, 0, 1, 0],
[1, 1, 1, 2, 2, 0, 1, 0],
[1, 1, 1, 2, 2, 2, 2, 0],
[1, 1, 1, 1, 1, 2, 1, 1],
[1, 1, 1, 1, 1, 2, 2, 1],
	]
m = len(screen)
n = len(screen[0])
x = 4
y = 4
prevC = screen[x][y]
newC = 3
floodFill(screen, m, n, x, y, prevC, newC)
for i in range(m):
	for j in range(n):
		print(screen[i][j], end =' ')
	print()
