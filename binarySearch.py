



def binary(arr, l, r, x):


	if r >= l:

		mid = l + (r - l) // 2

		
		if arr[mid] == x:
			return mid

	
		elif arr[mid] > x:
			return binary(arr, l, mid-1, x)

		
		else:
			return binary(arr, mid + 1, r, x)

	else:
		
		return -1



arr = [6, 9, 4, 25, 60]
x = 25


result = binary(arr, 0, len(arr)-1, x)

if result != -1:
	print("Element is present at index % d" % result)
else:
	print("Element is not present in array")

