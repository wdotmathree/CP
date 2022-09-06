/*
	Since we only care about the number of clients Valera can serve, we can greedily select the clients
	We sort the clients in ascending order by how much memory Valera needs to use to serve them
	We iterate through the clients and serve each of them, keeping track of the memory used
	When we don't have enough memory to serve the client, print the clients successfully served
	Otherwise, if we got through all clients, print all clients
*/

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
	return 0;
}
