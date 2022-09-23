#include <bits/stdc++.h>
using namespace std;

unsigned long long merge(int A[], int p, int q, int r) {
	unsigned long long inv = 0;
	int n1 = q - p + 1;
	int n2 = r - q;
	int L[n1 + 1];
	int R[n2 + 1];
	for (int i = 0; i < n1; i++) {
		L[i] = A[p + i];
	}
	for (int j = 0; j < n2; j++) {
		R[j] = A[q + j + 1];
	}
	L[n1] = INT_MAX;
	R[n2] = INT_MAX;
	int i = 0;
	int j = 0;
	for (int k = p; k <= r; k++) {
		if (L[i] < R[j]) {
			A[k] = L[i];
			i++;
		} else {
			A[k] = R[j];
			j++;
			inv += n1 - i;
		}
	}
	return inv;
}

unsigned long long mergeSort(int A[], int p, int r) {
	unsigned long long inv = 0;
	if (p < r) {
		int q = (p + r) / 2;
		inv += mergeSort(A, p, q);
		inv += mergeSort(A, q + 1, r);
		inv += merge(A, p, q, r);
	}
	return inv;
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
		int arr[a];
		for (int i = 0; i < a; i++) {
			cin >> arr[i];
		}
		unsigned long long inv = mergeSort(arr, 0, a);
		cout << inv << '\n';
	}
	return 0;
}
