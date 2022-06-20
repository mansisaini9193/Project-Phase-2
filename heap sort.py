def heapify(arr, r, f):
	large = f 
	l = 2 * f + 1
	root = 2 * f + 2	 

	if l < r and arr[f] < arr[l]:
		large = l

	if root < r and arr[large] < arr[root]:
		large = root


	if large != f:
	    arr[f], arr[large] = arr[large], arr[f]
	    heapify(arr, r, large)


def Heap_S(arr):
	r = len(arr)


	for f in range(r // 2 - 1, -1, -1):
		heapify(arr, r, f)

	
	for f in range(r-1, 0, -1):
		arr[f], arr[0] = arr[0], arr[f] 
		heapify(arr, f, 0)


arr = [ 5, 33, 12, 89, 55, 20, 24, 8]
print("The original array is: ", arr)
Heap_S(arr)
r = len(arr)
print ("Array after sorting is: ", arr)
