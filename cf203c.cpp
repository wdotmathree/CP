#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, d, a, b;
	cin >> n >> d >> a >> b;
	tuple<int, int, int> clients[n];
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		clients[i] = {x, y, i + 1};
	}
	sort(clients, clients + n,
		 [a, b](tuple<int, int, int> x, tuple<int, int, int> y) { return get<0>(x) * a + get<1>(x) * b < get<0>(y) * a + get<1>(y) * b; });
	unsigned long long ans = 0;
	int numclients = 0;
	while (ans <= d && numclients < n) {
		ans += get<0>(clients[numclients]) * a + get<1>(clients[numclients]) * b;
		numclients++;
	}
	if (ans <= d) {
		numclients = n + 1;
	}
	cout << numclients - 1 << '\n';
	for (int i = 0; i < numclients - 1; i++) {
		cout << get<2>(clients[i]);
		if (i != numclients - 2)
			cout << ' ';
		else
			cout << endl;
	}
}
