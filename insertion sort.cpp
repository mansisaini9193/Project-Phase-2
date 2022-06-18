

#include <bits/stdc++.h>
using namespace std;


void insertionS(int arr[], int m)
{
	int y, key, x;
	for (y = 1; y < m; y++)
	{
		key = arr[y];
		x = y - 1;

		
		while (x >= 0 && arr[x] > key)
		{
			arr[x + 1] = arr[x];
			x = x - 1;
		}
		arr[x + 1] = key;
	}
}


void printArray(int arr[], int m)
{
	int y;
	for (y = 0; y < m; y++)
		cout << arr[y] << " ";
	cout << endl;
}


int main()
{
	int arr[] = { 40, 22, 66, 8, 9 };
	int M = sizeof(arr) / sizeof(arr[0]);

	insertionS(arr, M);
	printArray(arr, M);

	return 0;
}

