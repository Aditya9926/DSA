#include <bits/stdc++.h>
using namespace std;

// Optimized: Added early termination flag
// Best case: O(n) when array is already sorted
// Worst case: O(n^2)
void bubbleSort(int arr[], int n)
{
	for (int i = 0; i < n - 1; i++) {
		bool swapped = false;
		for (int j = 0; j < n - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				swap(arr[j], arr[j + 1]);
				swapped = true;
			}
		}
		// If no swaps occurred in this pass, array is sorted
		if (!swapped) {
			break;
		}
	}
}

void printArray(int arr[], int size)
{
	for (int i = 0; i < size; i++)
		cout << arr[i] << " ";
	cout << endl;
}

int main()
{
	int arr[] = { 5, 1, 4, 2, 8};
    cout << "Array before sorting : ";
    for(int i : arr){
        cout << i << " ";
    }
	int N = sizeof(arr) / sizeof(arr[0]);
	bubbleSort(arr, N);
	cout << "\nArray after sorting : ";
	printArray(arr, N);

	// Test early termination with already sorted array
	int sorted_arr[] = {1, 2, 3, 4, 5};
	int M = sizeof(sorted_arr) / sizeof(sorted_arr[0]);
	cout << "\nAlready sorted array : ";
	printArray(sorted_arr, M);
	bubbleSort(sorted_arr, M);
	cout << "After sorting (early termination): ";
	printArray(sorted_arr, M);

	return 0;
}