
#include <bits/stdc++.h>
#include <string.h>
using namespace std;
#define RANGE 256


void countS(char arr[])
{
	
	char output[strlen(arr)];

	
	int count[RANGE + 1], h;
	memset(count, 0, sizeof(count));

	
	for (h = 0; arr[h]; ++h)
		++count[arr[h]];

	
	for (h = 1; h <= RANGE; ++h)
		count[h] += count[h - 1];

	
	for (h = 0; arr[h]; ++h) {
		output[count[arr[h]] - 1] = arr[h];
		--count[arr[h]];
	}

	


	for (h = 0; arr[h]; ++h)
		arr[h] = output[h];
}


int main()
{
	char arr[] = "newfile";
	countS(arr);

	cout << "Sorted character array is " << arr;
	return 0;
}


