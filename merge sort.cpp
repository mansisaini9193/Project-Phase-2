
#include <iostream>
using namespace std;



void merge(int array[], int const left, int const mid, int const right)
{
	auto const subAOne = mid - left + 1;
	auto const subATwo = right - mid;

	
	auto *leftArray = new int[subAOne],
		*rightArray = new int[subATwo];

	
	for (auto k = 0; k < subAOne; k++)
		leftArray[k] = array[left + k];
	for (auto f = 0; f < subATwo; f++)
		rightArray[f] = array[mid + 1 + f];

	auto indexOfSubAOne = 0, 
		indexOfSubATwo = 0; 
	int indexOfMergedA = left; 

	
	while (indexOfSubAOne < subAOne && indexOfSubATwo < subATwo) {
		if (leftArray[indexOfSubAOne] <= rightArray[indexOfSubATwo]) {
			array[indexOfMergedA] = leftArray[indexOfSubAOne];
			indexOfSubAOne++;
		}
		else {
			array[indexOfMergedA] = rightArray[indexOfSubATwo];
			indexOfSubATwo++;
		}
		indexOfMergedA++;
	}
	
	while (indexOfSubAOne < subAOne) {
		array[indexOfMergedA] = leftArray[indexOfSubAOne];
		indexOfSubAOne++;
		indexOfMergedA++;
	}
	while (indexOfSubATwo < subATwo) {
		array[indexOfMergedA] = rightArray[indexOfSubATwo];
		indexOfSubATwo++;
		indexOfMergedA++;
	}
}


void mergeSort(int array[], int const begin, int const end)
{
	if (begin >= end)
		return; 
	auto mid = begin + (end - begin) / 2;
	mergeSort(array, begin, mid);
	mergeSort(array, mid + 1, end);
	merge(array, begin, mid, end);
}


void printArray(int A[], int size)
{
	for (auto k = 0; k < size; k++)
		cout << A[k] << " ";
}


int main()
{
	int arr[] = { 23, 17, 2, 67, 10, 88 };
	auto arr_size = sizeof(arr) / sizeof(arr[0]);

	cout << "Given array is \n";
	printArray(arr, arr_size);

	mergeSort(arr, 0, arr_size - 1);

	cout << "\nSorted array is \n";
	printArray(arr, arr_size);
	return 0;
}
