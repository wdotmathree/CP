#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	unordered_map<int, int> freqs;
	while (n--) {
		int x;
		cin >> x;
		freqs[x]++;
	}
	int max = 0;
	int max2 = 0;
	for (auto x : freqs) {
		if (x.second > max) {
			max2 = max;
			max = x.second;
		}
	}
	vector<int> maxs;
	vector<int> max2s;
	for (auto x : freqs)
		if (x.second == max)
			maxs.push_back(x.first);
		else if (x.second == max2)
			max2s.push_back(x.first);
	int maxans = 0;
	sort(maxs.begin(), maxs.end());
	sort(max2s.begin(), max2s.end());
	if (maxs.size() >= 2) {
		maxans = std::max(maxans, abs(maxs[0] - maxs[maxs.size() - 1]));
	} else if (max2s.size() >= 2) {
		maxans = std::max(maxans, std::max(abs(maxs[0] - max2s[0]), abs(maxs[0] - max2s[max2s.size() - 1])));
	} else if (max2s.size() == 0) {
		maxans = 0;
	} else {
		maxans = abs(maxs[0] - max2s[0]);
	}
	cout << maxans << endl;
	return 0;
}
