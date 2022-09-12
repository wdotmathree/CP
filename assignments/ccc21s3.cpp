#include <bits/stdc++.h>
using namespace std;
vector<tuple<int, int, int>> a;

long long walk(int p) {
	long long ans = 0;
	for (int i = 0; i < a.size(); i++) {
		long long sum = max(0, abs(p - get<0>(a[i])) - get<2>(a[i]));
		ans += sum * get<1>(a[i]);
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
	int l, r;
	for (int i = 0; i < n; i++) {
		cin >> x >> y >> z;
		l = min(l, x);
		r = max(r, x);
		a.push_back({x, y, z});
	}
	int m;
	while (l < r) {
		m = (l + r) / 2;
		long long sum = walk(m);
		long long sum2 = walk(m + 1);
		if (sum < sum2) {
			r = m;
		} else {
			l = m + 1;
		}
	}
	cout << walk(l) << endl;
	return 0;
}
