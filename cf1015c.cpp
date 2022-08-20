#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin >> n >> m;
	pair<int, int> songs[n];
	unsigned long long sum = 0;
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		songs[i] = {x, y};
		sum += x;
	}
	sort(songs, songs + n, [](pair<int, int> a, pair<int, int> b) { return a.first - a.second > b.first - b.second; });
	int ans = -1;
	if (sum <= m) {
		ans = 0;
	} else {
		for (int i = 1; i <= n; i++) {
			sum -= songs[i - 1].first - songs[i - 1].second;
			if (sum <= m) {
				ans = i;
				break;
			}
		}
	}
	cout << ans << endl;
	return 0;
}
