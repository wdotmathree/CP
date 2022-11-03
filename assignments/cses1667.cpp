#include <bits/stdc++.h>
using namespace std;

void retrace(vector<int> prev, int curr) {
	stack<int> reversed;
	while (curr != 1) {
		reversed.push(curr);
		curr = prev[curr];
	}
	cout << reversed.size() + 1 << "\n1";
	while (!reversed.empty()) {
		cout << ' ' << reversed.top();
		reversed.pop();
	}
	cout << endl;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin >> n >> m;
	vector<int> connections[n + 1];
	int x, y;
	for (int i = 0; i < m; i++) {
		cin >> x >> y;
		connections[x].push_back(y);
		connections[y].push_back(x);
	}
	vector<int> prev(n + 1, -1);
	vector<bool> visited(n + 1, false);
	queue<int> q;
	q.push(1);
	visited[1] = true;
	while (!q.empty()) {
		int curr = q.front();
		q.pop();
		for (int x : connections[curr]) {
			if (!visited[x]) {
				q.push(x);
				prev[x] = curr;
				visited[x] = true;
			}
			if (x == n) {
				retrace(prev, x);
				return 0;
			}
		}
	}
	cout << "IMPOSSIBLE" << endl;
	return 0;
}
