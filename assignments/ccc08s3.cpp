#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int r, c;
		cin >> r >> c;
		char maze[r][c];
		char in;
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				cin >> in;
				maze[i][j] = in;
			}
		}
		if (maze[r - 1][c - 1] == '*') {
			cout << "-1\n";
			continue;
		}
		queue<pair<int, int>> q;
		int dist[r][c];
		memset(dist, -1, r * c * sizeof(int));
		q.push({0, 0});
		while (!q.empty()) {
			pair<int, int> pos = q.front();
			if (pos.first == 0 && pos.second == 0)
				dist[0][0] = 1;
			char curr = maze[pos.first][pos.second];
			q.pop();
			if (pos.first + 1 == r && pos.second + 1 == c)
				break;
			if (curr == '+') {
				if (pos.first != 0) {
					if (dist[pos.first - 1][pos.second] == -1) {
						q.push({pos.first - 1, pos.second});
						dist[pos.first - 1][pos.second] = dist[pos.first][pos.second] + 1;
					}
				}
				if (pos.second != 0) {
					if (dist[pos.first][pos.second - 1] == -1) {
						q.push({pos.first, pos.second - 1});
						dist[pos.first][pos.second - 1] = dist[pos.first][pos.second] + 1;
					}
				}
				if (pos.first + 1 != r) {
					if (dist[pos.first + 1][pos.second] == -1) {
						q.push({pos.first + 1, pos.second});
						dist[pos.first + 1][pos.second] = dist[pos.first][pos.second] + 1;
					}
				}
				if (pos.second + 1 != c) {
					if (dist[pos.first][pos.second + 1] == -1) {
						q.push({pos.first, pos.second + 1});
						dist[pos.first][pos.second + 1] = dist[pos.first][pos.second] + 1;
					}
				}
			} else if (curr == '-') {
				if (pos.second != 0) {
					if (dist[pos.first][pos.second - 1] == -1) {
						q.push({pos.first, pos.second - 1});
						dist[pos.first][pos.second - 1] = dist[pos.first][pos.second] + 1;
					}
				}
				if (pos.second + 1 != c) {
					if (dist[pos.first][pos.second + 1] == -1) {
						q.push({pos.first, pos.second + 1});
						dist[pos.first][pos.second + 1] = dist[pos.first][pos.second] + 1;
					}
				}
			} else if (curr == '|') {
				if (pos.first != 0) {
					if (dist[pos.first - 1][pos.second] == -1) {
						q.push({pos.first - 1, pos.second});
						dist[pos.first - 1][pos.second] = dist[pos.first][pos.second] + 1;
					}
				}
				if (pos.first + 1 != r) {
					if (dist[pos.first + 1][pos.second] == -1) {
						q.push({pos.first + 1, pos.second});
						dist[pos.first + 1][pos.second] = dist[pos.first][pos.second] + 1;
					}
				}
			}
		}
		cout << dist[r - 1][c - 1] << '\n';
	}
	return 0;
}
