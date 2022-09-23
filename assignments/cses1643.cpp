#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	long long arr[n];
	long long x;
	for (int i = 0; i < n; i++) {
		cin >> x;
		arr[i] = x;
	}
	long long sum = 0;
	long long max = LONG_LONG_MIN;
	for (int i = 0; i < n; i++) {
		sum = std::max(arr[i], sum + arr[i]);
		max = std::max(max, sum);
	}
	cout << max << endl;
	return 0;
}
