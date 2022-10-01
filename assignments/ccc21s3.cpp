#include <bits/stdc++.h>
using namespace std;
vector<tuple<int, int, int>> a;

unsigned long long walk(int p) {
	unsigned long long ans = 0;
	for (long unsigned int i = 0; i < a.size(); i++) {
		ans += (unsigned long long)(max(0, abs(p - get<0>(a[i])) - get<2>(a[i]))) * get<1>(a[i]);
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
	int x, y, z;
	int l = INT_MAX;
	int r = INT_MIN;
	for (int i = 0; i < n; i++) {
		cin >> x >> y >> z;
		l = min(l, x);
		r = max(r, x);
		a.push_back({x, y, z});
	}
	int m;
	while (l < r) {
		m = (l + r) / 2;
		if (walk(m) < walk(m + 1)) {
			r = m;
		} else {
			l = m + 1;
		}
	}
	cout << walk(l) << endl;
	return 0;
}
