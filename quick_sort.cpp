#include <bits/stdc++.h>
using namespace std;

int partition(int arr[], int low, int high) {
	int pivot = arr[low];
	while (low < high) {
		while (low < high && arr[high] >= pivot)
			high--;
		swap(arr[low], arr[high]);
		while (low < high && arr[low] <= pivot)
			low++;
		swap(arr[low], arr[high]);
	}
	return low;
}

void quick_sort(int *arr, int low, int high) {
	if (low < high) {
		int pi = partition(arr, low, high);
		quick_sort(arr, low, pi - 1);
		quick_sort(arr, pi + 1, high);
	}
}

int main() {
	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	clock_t t;
	t = clock();
	quick_sort(a, 0, n - 1);
	t = clock() - t;
	double time_taken = ((double)t) / CLOCKS_PER_SEC; // in seconds
	cout << "Time taken by function is: " << time_taken << endl;
	// for (int i = 0; i < n; i++) {
	// 	cout << a[i] << " ";
	// }
	// cout << endl;
	return 0;
}
