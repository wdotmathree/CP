#include <bits/stdc++.h>
using namespace std;

int resolvecrystal(int x, int y) {
	if (y == 2 && x == 2)
		return 1;
	if (y == 1 && (x == 1 || x == 3))
		return 1;
	if (y == 1 && x == 2)
		return 2;
	if (y == 0 && (x == 1 || x == 2 || x == 3))
		return 2;
	return 0;
}

bool fractal(int m, int x, int y) {
	if (m == 1) {
		return resolvecrystal(x, y) == 2;
	}
	int gridsize = pow(5, m - 1);
	int cx = x / gridsize;
	int cy = y / gridsize;
	if (resolvecrystal(cx, cy) == 1)
		return fractal(m - 1, x % gridsize, y % gridsize);
	else
		return resolvecrystal(cx, cy);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int m, x, y;
		cin >> m >> x >> y;
		cout << (fractal(m, x, y) ? "crystal" : "empty") << endl;
	}
	return 0;
}
