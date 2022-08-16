#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<tuple<int, int, int>> jobs;
		int i = 0;
		while (n--) {
			int x, y;
			cin >> x >> y;
			jobs.push_back({x, y, i});
			i++;
		}
		stable_sort(jobs.begin(), jobs.end(), [](tuple<int, int, int> x, tuple<int, int, int> y) {
			return (float)get<1>(x) / (float)get<0>(x) > (float)get<1>(y) / (float)get<0>(y);
		});
		for (auto x : jobs) {
			if (x != jobs[0])
				putchar(32);
			cout << get<2>(x) + 1;
		}
		if (t)
			cout << "\n\n";
		else
			cout << endl;
	}
	return 0;
}
