#include <bits/stdc++.h>
using namespace std;

vector<int> *paths;

pair<int, int> furthest(int dist, int node, int parent) {
	if (paths[node].size() == 1 && paths[node][0] == parent) {
		return {dist, node};
	}
	pair<int, int> ans = {INT_MIN, -1}, temp;
	for (int x : paths[node]) {
		if (x == parent)
			continue;
		temp = furthest(dist + 1, x, node);
		if (temp.first > ans.first) {
			ans = temp;
		}
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	if (n == 1) {
		cout << '0' << endl;
		return 0;
	}
	paths = (vector<int> *)calloc(n + 1, sizeof(vector<int>));
	int x, y;
	for (int i = 1; i < n; i++) {
		cin >> x >> y;
		paths[x].push_back(y);
		paths[y].push_back(x);
	}
	pair<int, int> temp = furthest(0, 1, -1);
	temp = furthest(0, temp.second, -1);
	cout << temp.first << endl;
	return 0;
}
