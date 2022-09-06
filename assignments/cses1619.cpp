#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	int arrivals[n], departures[n];
	int a, b;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		arrivals[i] = a;
		departures[i] = b;
	}
	sort(arrivals, arrivals + n);
	sort(departures, departures + n);
	int ai = 0;
	int bi = 0;
	int num = 0;
	int maxnum = 0;
	while (ai < n) {
		if (arrivals[ai] < departures[bi]) {
			ai++;
			maxnum = max(++num, maxnum);
		} else {
			bi++;
			num--;
		}
	}
	cout << maxnum << endl;
	return 0;
}
