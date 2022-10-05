#include <bits/stdc++.h>
using namespace std;

int gcf(int a, int b) {
	if (b == 0)
		return a;
	return gcf(b, a % b);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	vector<int> a;
	int x;
	a.reserve(n);
	while (n--) {
		cin >> x;
		a.push_back(x);
	}
	int largest = 0;
	for (int i = 0; i < a.size(); i++) {
		for (int j = 0; j < a.size(); j++) {
			if (i == j)
				continue;
			largest = max(largest, gcf(a[i], a[j]));
		}
	}
	cout << largest << endl;
	return 0;
}
