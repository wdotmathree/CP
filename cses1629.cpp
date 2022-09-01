#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	vector<pair<int, int>> a;
	int x, y;
	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		a.push_back({x, y});
	}
	sort(a.begin(), a.end(), [](pair<int, int> a, pair<int, int> b) { return a.second == b.second ? a.first < b.first : a.second < b.second; });
	int currenttime = 0;
	int ans = 0;
	for (pair<int, int> movie : a) {
		if (movie.first >= currenttime) {
			ans++;
			currenttime = movie.second;
		}
	}
	cout << ans << endl;
	return 0;
}
