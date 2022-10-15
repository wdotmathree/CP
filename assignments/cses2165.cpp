#include <bits/stdc++.h>
using namespace std;

void hanoi(int n, int a, int b) {
	if (n == 1) {
		cout << a << ' ' << b << '\n';
		return;
	}
	hanoi(n - 1, a, 6 - b - a);
	cout << a << ' ' << b << '\n';
	hanoi(n - 1, 6 - b - a, b);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	cout << exp2(n) - 1 << '\n';
	hanoi(n, 1, 3);
	return 0;
}
