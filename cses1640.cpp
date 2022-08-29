#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, x;
	cin >> n >> x;
	pair<int, int> arr[n];
	int y;
	for (int i = 0; i < n; i++) {
		cin >> y;
		arr[i] = {y, i + 1};
	}
	sort(arr, arr + n);
	int l = 0;
	int r = n - 1;
	while (l < r) {
		if (arr[l].first + arr[r].first < x) {
			l++;
		} else if (arr[l].first + arr[r].first > x) {
			r--;
		} else {
			cout << arr[l].second << ' ' << arr[r].second << endl;
			return 0;
		}
	}
	cout << "IMPOSSIBLE\n";
	return 0;
}
