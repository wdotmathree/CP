#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin >> n >> m;
	vector<int> roads[n + 1];
	unordered_set<int> disconnected;
	unordered_set<long long> built;
	int x, y;
	for (int i = 0; i < m; i++) {
		cin >> x >> y;
		roads[x].push_back(y);
		roads[y].push_back(x);
	}
	for (int i = 2; i <= n; i++) {
		disconnected.insert(i);
	}
	queue<int> q;
	unordered_set<int> visited;
	int curr;
	q.push(1);
	while (!disconnected.empty()) {
		while (!q.empty()) {
			curr = q.front();
			q.pop();
			if (visited.find(curr) != visited.end())
				continue;
			visited.insert(curr);
			disconnected.erase(curr);
			for (int x : roads[curr]) {
				q.push(x);
			}
		}
		if (!disconnected.empty()) {
			built.insert(curr | ((long long)*disconnected.begin() << 32));
			q.push(*disconnected.begin());
			disconnected.erase(disconnected.begin());
		}
	}
	cout << built.size() << '\n';
	for (long long x : built)
		cout << (x & 0xffffffff) << ' ' << (x >> 32) << '\n';
	return 0;
}
