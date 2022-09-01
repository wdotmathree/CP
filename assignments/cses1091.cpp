#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin >> n >> m;
	multiset<int, greater<int>> h;
	vector<int> t;
	t.reserve(m);
	vector<bool> sold;
	sold.resize(m);
	int x;
	while (n--) {
		cin >> x;
		h.insert(x);
	}
	while (m--) {
		cin >> x;
		t.push_back(x);
	}
	set<int>::iterator ticket;
	for (int x : t) {
		ticket = h.lower_bound(x);
		if (ticket != h.end()) {
			cout << *ticket << '\n';
			h.erase(ticket);
		} else {
			cout << "-1\n";
		}
	}
}
