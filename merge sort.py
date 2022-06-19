

def merge(arr, p, v, c):
	n1 = v- p + 1
	n2 = c - v

	
	P = [0] * (n1)
	C= [0] * (n2)

	
	for i in range(0, n1):
		P[i] = arr[p + i]

	for j in range(0, n2):
		C[j] = arr[v + 1 + j]

	
	i = 0	 
	j = 0	 
	k = p	 
	while i < n1 and j < n2:
		if P[i] <= C[j]:
			arr[k] = P[i]
			i += 1
		else:
			arr[k] = C[j]
			j += 1
		k += 1


	while i < n1:
		arr[k] = P[i]
		i += 1
		k += 1

	
	while j < n2:
		arr[k] = C[j]
		j += 1
		k += 1


def mergeSort(arr, p, r):
	if p < r:

		
		m = p+(r-p)//2

		
		mergeSort(arr, p, m)
		mergeSort(arr, m+1, r)
		merge(arr, p, m, r)



arr = [44, 19, 33, 2, 9, 43]
n = len(arr)
print("Given array is")
for i in range(n):
	print("%d" % arr[i],end=" ")

mergeSort(arr, 0, n-1)
print("\n\nSorted array is")
for i in range(n):
	print("%d" % arr[i],end=" ")


