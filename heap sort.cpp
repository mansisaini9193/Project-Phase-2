
#include <iostream>
using namespace std;


void heapify(int arr[], int c, int q)
{
	int largest = q; 
	int l = 2 * q + 1; 
	int r = 2 * q + 2; 

	
	if (l < c && arr[l] > arr[largest])
		largest = l;

	
	if (r < c && arr[r] > arr[largest])
		largest = r;

	
	if (largest != q) {
		swap(arr[q], arr[largest]);

		
		heapify(arr, c, largest);
	}
}


void heapSort(int arr[], int c)
{
	
	for (int q = c / 2 - 1; q >= 0; q--)
		heapify(arr, c, q);

	
	for (int q = c - 1; q >= 0; q--) {
		
		swap(arr[0], arr[q]);

		
		heapify(arr, q, 0);
	}
}


void printArray(int arr[], int c)
{
	for (int q = 0; q < c; ++q)
		cout << arr[q] << " ";
	cout << "\n";
}


int main()
{
	int arr[] = { 23, 90, 12, 2, 66, 78 };
	int s = sizeof(arr) / sizeof(arr[0]);

	heapSort(arr, s);

	cout << "Sorted array is \n";
	printArray(arr, s);
}
