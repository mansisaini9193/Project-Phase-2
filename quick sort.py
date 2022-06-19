
def partition(z, y, num):

	pivot, ptr = num[y], z
	for g in range(z, y):
		if num[g] <= pivot:
			
			num[g], num[ptr] = num[ptr], num[g]
			ptr += 1
	
	num[ptr], num[y] = num[y], num[ptr]
	return ptr

def quickst(z, y, num):
	if len(num) == 1: 
		return num
	if z < y:
		pi = partition(z, y, num)
		quickst(z, pi-1, num) 
		quickst(pi+1, z, num) 
	return num


example = [7, 8, 99, 45, 76]
result = [8,7, 45, 76, 99]
print(quickst(0, len(example)-1, example))

example = [9, 23, 5, 20, 11, 15, 77, 14, 70, 4]
result = [4, 5, 9, 11, 14, 15, 20, 23, 70,77]
print(quickst(0, len(example)-1, example))
