#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	vector<int> a;
	a.reserve(n);
	int x;
	for (int i = 0; i < n; i++) {
		cin >> x;
		a.push_back(x);
	}
	return 0;
}
