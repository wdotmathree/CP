#include <bits/stdc++.h>
using namespace std;

void merge(int *array, int l, int m, int r, int &inv) {
	int i, j, k, nl, nr;
	// size of left and right sub-arrays
	nl = m - l + 1;
	nr = r - m;
	int larr[nl], rarr[nr];
	// fill left and right sub-arrays
	for (i = 0; i < nl; i++)
		larr[i] = array[l + i];
	for (j = 0; j < nr; j++)
		rarr[j] = array[m + 1 + j];
	i = 0;
	j = 0;
	k = l;
	// marge temp arrays to real array
	while (i < nl && j < nr) {
		if (larr[i] <= rarr[j]) {
			array[k] = larr[i];
			i++;
		} else {
			array[k] = rarr[j];
			j++;
			inv += (r - m - i);
		}
		k++;
	}
	while (i < nl) { // extra element in left array
		array[k] = larr[i];
		i++;
		k++;
	}
	while (j < nr) { // extra element in right array
		array[k] = rarr[j];
		j++;
		k++;
	}
}

void mergeSort(int *array, int l, int r, int &inv) {
	int m;
	if (l < r) {
		int m = l + (r - l) / 2;
		// Sort first and second arrays
		mergeSort(array, l, m, inv);
		mergeSort(array, m + 1, r, inv);
		merge(array, l, m, r, inv);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	while (true) {
		int a;
		cin >> a;
		if (a == 0)
			break;
		int *arr = (int *)malloc(sizeof(int) * a);
		for (int i = 0; i < a; i++) {
			int x;
			cin >> x;
			arr[i] = x;
		}
		int inv = 0;
		mergeSort(arr, 0, a, inv);
		free(arr);
		cout << inv << '\n';
	}
	return 0;
}
