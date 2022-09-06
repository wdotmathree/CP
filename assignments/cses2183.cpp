#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	vector<int> a;
	a.reserve(n);
	int x;
	for (int i = 0; i < n; i++) {
		cin >> x;
		a.push_back(x);
	}
	sort(a.begin(), a.end());
	long long sum = 0;
	int i = 0;
	// If there is no gap between the current max sum and the next number, it means we can make every number up to and including that next number
	// We know this because the program has not exited yet, meaning all numbers before this can also be made
	// If there is a gap, it means the next number cannot be made and the program exits
	while (sum + 1 >= a[i] && i < n) {
		sum += a[i++];
	}
	cout << sum + 1 << endl;
	return 0;
}
