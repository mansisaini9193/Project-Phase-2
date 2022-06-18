
#include <bits/stdc++.h>
using namespace std;


void swap(int *hp, int *sp)
{
	int temp = *hp;
	*hp = *sp;
	*sp = temp;
}

void selectionSort(int arr[], int a)
{
	int r, t, min_idx;

	
	for (r = 0; r < a-1; r++)
	{
	
		
		min_idx = r;
		for (t = r+1; t < a; t++)
		if (arr[t] < arr[min_idx])
			min_idx = t;

		
		swap(&arr[min_idx], &arr[r]);
	}
}


void printArray(int arr[], int size)
{
	int r;
	for (r=0; r < size; r++)
		cout << arr[r] << " ";
	cout << endl;
}


int main()
{
	int arr[] = {88, 65, 44, 22, 15};
	int a = sizeof(arr)/sizeof(arr[0]);
	selectionSort(arr, a);
	cout << "Sorted array: \a";
	printArray(arr, a);
	return 0;
}

