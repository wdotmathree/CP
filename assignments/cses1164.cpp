#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	int x, y;
	multiset<pair<int, int>> arrivals;
	multiset<pair<int, int>> departures;
	unordered_set<int> available;
	unordered_map<int, int> allocated;
	int rooms = 0;
	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		arrivals.insert({x, i});
		departures.insert({y, i});
	}
	while (!arrivals.empty()) {
		if (arrivals.begin()->first <= departures.begin()->first) {
			if (available.empty()) {
				allocated[arrivals.begin()->second] = ++rooms;
			} else {
				int room = *available.begin();
				allocated[arrivals.begin()->second] = room;
				available.erase(room);
			}
			arrivals.erase(arrivals.begin());
		} else {
			available.insert(allocated[departures.begin()->second]);
			departures.erase(departures.begin());
		}
	}
	cout << rooms << endl;
	for (int i = 0; i < n; i++) {
		if (i)
			cout << ' ';
		cout << allocated[i];
	}
	cout << endl;
	return 0;
}
