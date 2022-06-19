
def insertionS(arr):


	for n in range(1, len(arr)):

		key = arr[n]

		
		w = n-1
		while w >=0 and key < arr[w] :
				arr[w+1] = arr[w]
				w -= 1
		arr[w+1] = key



arr = [56, 11, 23, 8, 64]
insertionS(arr)
print ("Sorted array is:")
for n in range(len(arr)):
	print ("%d" %arr[n])

