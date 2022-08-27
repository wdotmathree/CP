#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, x;
	cin >> n >> x;
	vector<int> p;
	p.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> p[i];
	}
	int ans = 0;
	int target;
	sort(p.begin(), p.end());
	int r = n - 1;
	for (int l = 0; l < r; l++) {
		target = x - p[l];
		while (p[r] > target)
			r--;
		if (l >= r)
			break;
		ans++;
		r--;
	}
	cout << ans + n - ans * 2 << endl;
}
