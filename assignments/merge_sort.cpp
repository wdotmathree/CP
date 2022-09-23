#include <bits/stdc++.h>
using namespace std;

void merge(int *arr, int l, int m, int r) {
	int n1 = m - l + 1;
	int n2 = r - m;
	int L[n1], R[n2];
	for (int i = 0; i < n1; i++)
		L[i] = arr[l + i];
	for (int i = 0; i < n2; i++)
		R[i] = arr[m + 1 + i];
	int i = 0, j = 0, k = l;
	while (i < n1 && j < n2) {
		if (L[i] <= R[j]) {
			arr[k] = L[i];
			i++;
		} else {
			arr[k] = R[j];
			j++;
		}
		k++;
	}
	while (i < n1) {
		arr[k] = L[i];
		i++;
		k++;
	}
	while (j < n2) {
		arr[k] = R[j];
		j++;
		k++;
	}
}

void merge_sort(int *arr, int l, int r) {
	if (l < r) {
		int m = l + (r - l) / 2;
		merge_sort(arr, l, m);
		merge_sort(arr, m + 1, r);
		merge(arr, l, m, r);
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
	merge_sort(a, 0, n - 1);
	t = clock() - t;
	double time_taken = ((double)t) / CLOCKS_PER_SEC; // in seconds
	cout << "Time taken by function is: " << time_taken << endl;
	// for (int i = 0; i < n; i++) {
	// 	cout << a[i] << " ";
	// }
	// cout << endl;
	return 0;
}
