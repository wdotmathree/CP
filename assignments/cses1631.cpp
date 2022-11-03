#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	multiset<pair<int, int>, std::greater<pair<int, int>>> a;
	multiset<pair<int, int>, std::less<pair<int, int>>> b;
	int x;
	for (int i = 0; i < n; i++) {
		cin >> x;
		a.insert({x, i});
		b.insert({x, i});
	}
	multiset<pair<int, int>>::iterator ca = a.begin(), cb = b.end();
	unsigned long long total = 0;
	int time = 0;
	while (!a.empty() && !b.empty()) {
		// No books are being read right now
		if (time == 0) {
			// If B has a longer book than A
			if ((--b.end())->first > a.begin()->first) {
				// Have B start reading the book
				cb = --b.end();
				time += cb->first;
				// Otherwise (prioritize A if they are equal)
			} else {
				// Have A start reading the book
				ca = a.begin();
				time -= ca->first;
			}
		}
		// A is not done reading
		if (time < 0) {
			// Pick the shortest book for B and start reading it
			cb = b.begin();
			// If A is reading the same book
			if (ca != a.end() && cb->second == ca->second) {
				// If there are no books left
				if (++cb == b.end()) {
					// Make A finish reading the current book
					total += ca->first;
					// Reset back to default state
					time = 0;
					a.erase(ca);
					ca = a.end();
					continue;
				}
			}
			time += cb->first;
			// If there was enough time to finish reading
			if (time <= 0) {
				// Finish reading the book
				// Remove from pile of books
				b.erase(cb);
				cb = b.end();
			} else {
				// Time is now how much time A has before B finishes reading
				// A has finished reading
				total += ca->first;
				a.erase(ca);
				ca = a.end();
			}
		}
		// B is not done reading
		if (time > 0) {
			// Pick the shortest book for A and start reading it
			ca = --a.end();
			// If B is reading the same book
			if (cb != b.end() && ca->second == cb->second) {
				// If there are no books left
				if (ca == a.begin()) {
					// Make B finish reading the current book
					total += cb->first;
					// Reset back to default state
					time = 0;
					b.erase(cb);
					cb = b.end();
					continue;
				}
				ca--;
			}
			time -= ca->first;
			// If there was enough time to finish reading
			if (time >= 0) {
				// Finish reading the book
				// Remove from pile of books
				a.erase(ca);
				ca = a.end();
			} else {
				// Time is now how much time B has before A finishes reading
				// B has finished reading
				total += cb->first;
				b.erase(cb);
				cb = b.end();
			}
		}
	}
	if (!a.empty()) {
		if (time > 0) {
			total -= time;
		}
		for (ca = a.begin(); ca != a.end(); ca++) {
			total += ca->first;
		}
	}
	if (!b.empty()) {
		if (time < 0) {
			total += time;
		}
		for (cb = b.begin(); cb != b.end(); cb++) {
			total += cb->first;
		}
	}
	cout << total << endl;
	return 0;
}
