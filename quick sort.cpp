
#include <iostream>
using namespace std;

int partition(int arr[], int start, int end)
{

	int pivot = arr[start];

	int count = 0;
	for (int z = start + 1; z<= end; z++) {
		if (arr[z] <= pivot)
			count++;
	}

	
	int pivotIndex = start + count;
	swap(arr[pivotIndex], arr[start]);

	
	int u = start, z = end;

	while (u < pivotIndex && z > pivotIndex) {

		while (arr[u] <= pivot) {
			u++;
		}

		while (arr[z] > pivot) {
			z--;
		}

		if (u < pivotIndex && z > pivotIndex) {
			swap(arr[u++], arr[z--]);
		}
	}

	return pivotIndex;
}

void quickSort(int arr[], int start, int end)
{

	
	if (start >= end)
		return;


	int s = partition(arr, start, end);

	
	quickSort(arr, start, s - 1);


	quickSort(arr, s + 1, end);
}

int main()
{

	int arr[] = { 23, 78, 56, 43, 12, 8 };
	int n = 6;

	quickSort(arr, 0, n - 1);

	for (int u = 0; u < n; u++) {
		cout << arr[u] << " ";
	}

	return 0;
}
