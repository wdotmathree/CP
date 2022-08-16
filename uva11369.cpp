#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> items;
		items.reserve(n);
		while (n--) {
			int x;
			cin >> x;
			items.push_back(x);
		}
		sort(items.rbegin(), items.rend());
		int ans = 0;
		int i = 1;
		for (auto p : items) {
			if (i % 3 == 0)
				ans += p;
			i++;
		}
		cout << ans << '\n';
	}
	return 0;
}
