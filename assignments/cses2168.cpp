#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	vector<pair<pair<int, int>, int>> ranges;
	ranges.reserve(n);
	int x, y;
	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		ranges.push_back({{x, y}, i});
	}
	sort(ranges.begin(), ranges.end(), [](pair<pair<int, int>, int> a, pair<pair<int, int>, int> b) {
		if (a.first.second - a.first.first == b.first.second - b.first.first)
			return a.first.first > b.first.first;
		return a.first.second - a.first.first < b.first.second - b.first.first;
	});
	unordered_map<int, int> positions;
	for (int i = 0; i < n; i++) {
		positions[ranges[i].second] = i;
	}
	for (int i = 0; i < n; i++) {
		int j = positions[i] - 1;
		unsigned short ans = 0;
		while (j >= 0) {
			if (ranges[j].first.first >= ranges[positions[i]].first.first && ranges[j].first.second <= ranges[positions[i]].first.second) {
				ans = 1;
				break;
			}
			j--;
		}
		if (i)
			cout << ' ';
		cout << ans;
	}
	cout << '\n';
	for (int i = 0; i < n; i++) {
		int j = positions[i] + 1;
		unsigned short ans = 0;
		while (j < n) {
			if (ranges[j].first.first <= ranges[positions[i]].first.first && ranges[j].first.second >= ranges[positions[i]].first.second) {
				ans = 1;
				break;
			}
			j++;
		}
		if (i)
			cout << ' ';
		cout << ans;
	}
	cout << endl;
	return 0;
}
