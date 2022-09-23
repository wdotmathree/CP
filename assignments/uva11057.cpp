#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	while (true) {
		int N;
		cin >> N;
		if (cin.eof())
			break;
		vector<int> prices;
		prices.reserve(N);
		while (N--) {
			int x;
			cin >> x;
			prices.push_back(x);
		}
		int m;
		cin >> m;
		sort(prices.begin(), prices.end());
		pair<int, int> best;
		auto l = prices.begin();
		auto r = prices.end() - 1;
		while (l < r) {
			if (*l + *r == m) {
				best = {*l, *r};
				l++;
				r--;
			}
			l += ((*l + *r) < m);
			r -= ((*l + *r) > m);
		}
		cout << "Peter should buy books whose prices are " << best.first << " and " << best.second << ".\n\n";
	}
	return 0;
}
