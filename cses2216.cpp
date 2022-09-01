#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	unordered_map<int, int> a;
	int x;
	for (int i = 0; i < n; i++) {
		cin >> x;
		a[x] = i;
	}
	int ans = 1;
	int idx = -1;
	for (int i = 1; i <= n; i++) {
		if (a[i] < idx)
			ans++;
		idx = a[i];
	}
	cout << ans << endl;
	return 0;
}
