#include <bits/stdc++.h>
using namespace std;

const int m = 1e9 + 7;

int pow(unsigned long long a, int b, int m) {
	unsigned long long res = 1;
	while (b) {
		if (b & 1)
			res = (res * a) % m;
		a = (a * a) % m;
		b >>= 1;
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, a, b, c;
	cin >> n;
	while (n--) {
		cin >> a >> b >> c;
		cout << pow(a, pow(b, c, m - 1), m) << endl;
	}
	return 0;
}
