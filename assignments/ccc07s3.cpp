#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	int assignments[10000];
	memset(assignments, -1, 40000);
	int a, b;
	while (n--) {
		cin >> a >> b;
		assignments[a] = b;
	}
	while (true) {
		cin >> a >> b;
		if (a == 0 && b == 0)
			return 0;
		int ptr = assignments[a];
		if (ptr == -1) {
			cout << "No\n";
			continue;
		}
		unordered_set<int> visited;
		int dist = -1;
		int tmpdist = 0;
		while (ptr != -1) {
			if (ptr == b) {
				dist = tmpdist;
				break;
			}
			if (visited.find(ptr) != visited.end())
				break;
			visited.insert(ptr);
			ptr = assignments[ptr];
			tmpdist++;
		}
		if (dist == -1)
			cout << "No\n";
		else
			cout << "Yes " << dist << '\n';
	}
	return 0;
}
