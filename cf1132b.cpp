#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		a[i] = x;
	}
	int m;
	cin >> m;
	int q[m];
	for (int i = 0; i < m; i++) {
		int x;
		cin >> x;
		q[i] = x;
	}
	sort(a, a + n, [](const int a, const int b) { return a > b; });
	unsigned long long sum = 0;
	for (int i = 0; i < n; i++) {
		sum += a[i];
	}
	for (int i = 0; i < m; i++) {
		cout << sum - a[q[i] - 1] << '\n';
	}
	return 0;
}
