#include <bits/stdc++.h>
using namespace std;

vector<int> a;

long long solve(int mid) {
	long long ans = 0;
	for (int x : a) {
		ans += abs(mid - x);
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	a.reserve(n);
	int x;
	for (int i = 0; i < n; i++) {
		cin >> x;
		a.push_back(x);
	}
	sort(a.begin(), a.end());
	if (a.size() % 2) {
		cout << solve(a[a.size() / 2]) << endl;
	} else {
		cout << min(solve(a[a.size() / 2]), solve(a[a.size() / 2 - 1]));
	}
	return 0;
}
