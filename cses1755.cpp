#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	unordered_map<char, int> a;
	char x;
	cin.read(&x, 1);
	while (x != -1 && x != 10) {
		a[x]++;
		cin.read(&x, 1);
	}
	deque<char> ans;
	int odd = 0;
	char oddchar = -1;
	for (pair<char, int> p : a) {
		if (p.second % 2) {
			odd++;
			oddchar = p.first;
		}
	}
	if (odd > 1) {
		cout << "NO SOLUTION\n";
		return 0;
	}
	if (odd == 1) {
		for (int i = 0; i < a[oddchar]; i++) {
			ans.push_back(oddchar);
		}
	}
	for (pair<char, int> p : a) {
		if (p.first == oddchar)
			continue;
		for (int i = 0; i < p.second / 2; i++) {
			ans.push_back(p.first);
			ans.push_front(p.first);
		}
	}
	for (char p : ans) {
		cout << p;
	}
	cout << endl;
	return 0;
}
