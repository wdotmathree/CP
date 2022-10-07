#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int m;
	cin >> m;
	while (m--) {
		int n;
		cin >> n;
		stack<int> hill, branch;
		int x;
		for (int i = 0; i < n; i++) {
			cin >> x;
			hill.push(x);
		}
		int next = 1;
		while (!hill.empty()) {
			if (hill.top() == next) {
				hill.pop();
				next++;
			} else {
				if (!branch.empty()) {
					if (branch.top() == next) {
						branch.pop();
						next++;
						continue;
					}
				}
				branch.push(hill.top());
				hill.pop();
			}
		}
		while (!branch.empty()) {
			if (branch.top() == next) {
				branch.pop();
				next++;
			} else {
				break;
			}
		}
		if (next == n + 1)
			cout << "Y\n";
		else
			cout << "N\n";
	}
	return 0;
}
