#include <bits/stdc++.h>
using namespace std;

int main() {
	int k, n;
	cin >> k >> n;
	int a[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	set<int> s;
	for (int i = 0; i < n; i++) {
		if (*s.begin() < a[i]) {
			s.insert(a[i]);
		} else if (s.size() < k) {
			s.insert(a[i]);
		}
		if (s.size() > k) {
			s.erase(s.begin());
		}
	}
	cout << *s.begin() << endl;
	return 0;
}
