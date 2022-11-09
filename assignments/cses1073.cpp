#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, x;
	cin >> n;
	vector<int> tops;
	while (n--) {
		cin >> x;
		vector<int>::iterator pos = upper_bound(tops.begin(), tops.end(), x);
		if (pos == tops.end()) {
			tops.push_back(x);
		} else {
			*pos = x;
		}
	}
	cout << tops.size() << endl;
	return 0;
}
