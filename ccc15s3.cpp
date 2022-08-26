#include <bits/stdc++.h>
using namespace std;

int G, P, ans = 0;
vector<int> requirements, available;

void solve() {
	for (int x : requirements) {
		vector<int>::iterator firstgate = upper_bound(available.begin(), available.end(), x);
		if (firstgate != available.begin()) {
			if (*(--firstgate) <= x) {
				ans++;
				available.erase(firstgate);
			} else {
				break;
			}
		} else {
			break;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> G >> P;
	requirements.reserve(P);
	for (int i = 0; i < P; i++) {
		int a;
		cin >> a;
		requirements.push_back(a);
	}
	available.reserve(G);
	for (int i = 1; i <= G; i++) {
		available.push_back(i);
	}

	solve();

	cout << ans << endl;
	return 0;
}
