#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	int pieces[2001] = {0};
	int x;
	while (n--) {
		cin >> x;
		pieces[x]++;
	}
	int boards[4001] = {0};
	for (int x = 1; x <= 2000; x++) {
		boards[x * 2] += pieces[x] / 2;
		for (int y = ++x; y < 2001; y++) {
			boards[x + y] += min(pieces[x], pieces[y]);
		}
	}
	for (int i = 1; i <= 10; i++) {
		cout << i << " " << boards[i] << endl;
	}
}
