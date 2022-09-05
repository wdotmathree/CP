#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	if ((int)((n + 1) * (n / 2.)) % 2) {
		cout << "NO\n";
	} else {
		long long lb, rb;
		if (n % 2) {
			lb = ceil(n / 4.);
			rb = ceil(n / 2.) + ceil(n / 4.) - 1;
		} else {
			lb = n / 4 + 1;
			rb = n / 2 + n / 4;
		}
		if ((long long)(((rb + 1) * (rb / 2.)) - (long long)(lb * ((lb - 1) / 2.))) * 2 != (long long)((n + 1) * (n / 2.))) {
			cout << "NO\n";
		} else {
			cout << "YES\n" << ceil(n / 2.) << '\n';
			for (int i = lb; i < rb; i++) {
				cout << i << ' ';
			}
			cout << rb << '\n' << n / 2 << '\n';
			for (int i = 1; i < lb; i++) {
				cout << i << ' ';
			}
			for (int i = rb + 1; i < n; i++) {
				cout << i << ' ';
			}
			cout << n << endl;
		}
	}
	return 0;
}
