#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int x, n, p;
	cin >> x >> n;
	set<int> lights{{0, x}};
	set<int>::iterator l, r;
	int interval = INT_MIN;
	char first = 1;
	while (n--) {
		cin >> p;
		lights.insert(p);
		r = lights.begin();
		l = r++;
		while (r != lights.end()) {
			interval = max(interval, *r - *l);
			l++;
			r++;
		}
		if (!first)
			cout << ' ';
		first = 0;
		cout << interval;
		interval = INT_MIN;
	}
	cout << endl;
	return 0;
}
