
def countS(arr):

	
	output = [0 for k in range(len(arr))]


	count = [0 for k in range(256)]

	
	ans = ["" for _ in arr]

	
	for k in arr:
		count[ord(k)] += 1

	
	for k in range(256):
		count[k] += count[k-1]

	
	for k in range(len(arr)):
		output[count[ord(arr[k])]-1] = arr[k]
		count[ord(arr[k])] -= 1


	for k in range(len(arr)):
		ans[k] = output[k]
	return ans


arr = "my new document"
ans = countS(arr)
print("Sorted character array is % s" %("".join(ans)))


