#include <bits/stdc++.h>
using namespace std;

int main() {
	const int p = 1e9 + 7;
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	unsigned int n, a, b;
	cin >> n;
	while (n--) {
		cin >> a >> b;
		if (b == 0) {
			cout << 1 << '\n';
			continue;
		} else if (a == 0) {
			cout << 0 << '\n';
			continue;
		} else if (a == 1) {
			cout << 1 << '\n';
			continue;
		} else if (b == 1) {
			cout << a << '\n';
			continue;
		}
		unsigned long long ans = 1;
		unsigned long long x = a;
		while (b) {
			if (b & 1) {
				ans = (ans * x) % p;
			}
			x = (x * x) % p;
			b >>= 1;
		}
		cout << ans << '\n';
	}
	return 0;
}
