/*
	Since the average is weighted evenly, we can greedily choose the exams to write essays for
	And since an unweighted average is the sum of points on every exam divided by the number of exams, we can multiply it by the number of
	exams to get a total number of points necessary to get the scholarship
	We can sort the exams in ascending order by how many essays to write for a 1 point increase and repeatedly write essays until the
	max number of points for that exam is reached
	In practice, we can take the minimum of number of essays to max out the points and the number of essays to get the scholarship
	if we only write essays for that exam and jump by adding the number of essays until either of those 2 things happen
*/

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
