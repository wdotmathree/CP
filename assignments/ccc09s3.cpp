#include <bits/stdc++.h>
using namespace std;

unordered_set<short> adj[51];

int bfs(short curr, short target) {
	short dist[51];
	memset(dist, -1, 51 * sizeof(short));
	queue<short> q;
	q.push(curr);
	dist[curr] = 0;
	while (!q.empty()) {
		short x = q.front();
		q.pop();
		for (short y : adj[x]) {
			if (dist[y] == -1) {
				dist[y] = dist[x] + 1;
				q.push(y);
			}
			if (y == target)
				break;
		}
	}
	return dist[target];
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	unordered_set<short> tmp;
	char op;
	short x, y;
	adj[1] = {6};
	adj[2] = {6};
	adj[3] = {4, 5, 6, 15};
	adj[4] = {4, 5, 6};
	adj[5] = {3, 4, 6};
	adj[6] = {1, 2, 3, 4, 5, 7};
	adj[7] = {6, 8};
	adj[8] = {7, 9};
	adj[9] = {8, 10, 12};
	adj[10] = {9, 11};
	adj[11] = {10, 12};
	adj[12] = {9, 11, 13};
	adj[13] = {12, 14, 15};
	adj[14] = {13};
	adj[15] = {3, 13};
	adj[16] = {17, 18};
	adj[17] = {16, 18};
	adj[18] = {16, 17};
	do {
		cin >> op;
		if (op == 'i') {
			cin >> x >> y;
			adj[x].insert(y);
			adj[y].insert(x);
		} else if (op == 'd') {
			cin >> x >> y;
			adj[x].erase(y);
			adj[y].erase(x);
		} else if (op == 'n') {
			cin >> x;
			cout << adj[x].size() << '\n';
		} else if (op == 'f') {
			cin >> x;
			for (int y : adj[x]) {
				tmp.insert(adj[y].begin(), adj[y].end());
			}
			for (int y : adj[x]) {
				tmp.erase(y);
			}
			cout << tmp.size() - 1 << '\n';
			tmp.clear();
		} else if (op == 's') {
			cin >> x >> y;
			int res = bfs(x, y);
			if (res == -1)
				cout << "Not connected\n";
			else
				cout << res << '\n';
		}
	} while (op != 'q');
	return 0;
}
