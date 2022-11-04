#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int h, w;
	scanf("%i %i", &h, &w);
	getchar();
	unordered_set<int> untouched;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (getchar() == '.') {
				untouched.insert(i * w + j);
			}
		}
		getchar();
	}
	unordered_set<int> visited;
	queue<int> q;
	if (untouched.empty()) {
		cout << '0' << endl;
		return 0;
	}
	q.push(*untouched.begin());
	untouched.erase(untouched.begin());
	int ans = 1;
	while (!untouched.empty()) {
		while (!q.empty()) {
			int curr = q.front();
			q.pop();
			if (visited.find(curr) != visited.end())
				continue;
			visited.insert(curr);
			untouched.erase(curr);
			if ((curr + 1) % w && untouched.find(curr + 1) != untouched.end())
				q.push(curr + 1);
			if (curr % w && untouched.find(curr - 1) != untouched.end())
				q.push(curr - 1);
			if (curr / w && untouched.find(curr - w) != untouched.end())
				q.push(curr - w);
			if ((curr / w) < (h - 1) && untouched.find(curr + w) != untouched.end())
				q.push(curr + w);
		}
		if (!untouched.empty()) {
			ans++;
			q.push(*untouched.begin());
			untouched.erase(untouched.begin());
		}
	}
	cout << ans << endl;
	return 0;
}
