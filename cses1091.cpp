#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	vector<int> h;
	h.reserve(n);
	vector<int> t;
	t.reserve(m);
	vector<bool> sold;
	sold.resize(m);
	int x;
	while (n--) {
		cin >> x;
		h.push_back(x);
	}
	while (m--) {
		cin >> x;
		t.push_back(x);
	}
	sort(h.begin(), h.end());
	vector<int>::iterator it;
	for (int customer : t) {
		it = upper_bound(h.begin(), h.end(), customer);
		if (it == h.begin()) {
			cout << "-1\n";
		} else if (it == h.end()) {
			if (*--it <= customer) {
				while (sold[it - h.begin()] && it != h.begin()) {
					it--;
				}
				if (it == h.begin()) {
					if (*it <= customer && !sold[it - h.begin()]) {
						cout << *it << '\n';
						sold[it - h.begin()] = true;
					} else {
						cout << "-1\n";
					}
				} else {

					cout << *it << '\n';
					sold[it - h.begin()] = true;
				}
			} else {
				cout << "-1\n";
			}
		} else {
			it--;
			while (sold[it - h.begin()] && it != h.begin()) {
				it--;
			}
			if (it == h.begin()) {
				if (*it <= customer && !sold[it - h.begin()]) {
					cout << *it << '\n';
					sold[it - h.begin()] = true;
				} else {
					cout << "-1\n";
				}
			} else {

				cout << *it << '\n';
				sold[it - h.begin()] = true;
			}
		}
	}
}
