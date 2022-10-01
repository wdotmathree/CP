#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, q, d, a, b;
	cin >> n;
	while (n--) {
		d = 1;
		a = 0;
		b = 9;
		cin >> q;
		while (b <= q) {
			a = b;
			b = b / d * 10 * ++d;
		}
		cout << (int)((a + ceil((float)(q - a) / d)) / pow(10, (d - ((q - a - 1) % d)) - 1)) % 10 << '\n';
	}
	return 0;
}
