#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	if (n == 1) {
		cout << "1" << endl;
		return 0;
	}
	int removed = 0;
	set<int> children;
	for (int i = 1; i <= n; i++)
		children.insert(i);
	set<int>::iterator it = ++children.begin();
	while (removed < n - 1) {
		cout << *it << ' ';
		children.erase(it++);
		if (it == children.end())
			it = children.begin();
		if (++it == children.end())
			it = children.begin();
		removed++;
	}
	cout << *children.begin() << endl;
	return 0;
}
