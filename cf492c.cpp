#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, r;
	unsigned long long target;
	cin >> n >> r >> target;
	pair<int, int> exams[n];
	unsigned long long sum = 0;
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		exams[i] = {x, y};
		sum += x;
	}
	target *= n;
	sort(exams, exams + n, [](pair<int, int> a, pair<int, int> b) { return a.second < b.second; });
	unsigned long long essays = 0;
	int maxed = 0;
	while (sum < target) {
		while (exams[maxed].first == r)
			maxed++;
		unsigned long long jump = target - sum;
		if (r - exams[maxed].first < jump)
			jump = r - exams[maxed].first;
		exams[maxed].first += jump;
		essays += exams[maxed].second * jump;
		sum += jump;
	}
	cout << essays << endl;
}
