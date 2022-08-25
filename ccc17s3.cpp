#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	int pieces[2001] = {0};
	int x;
	while (n--) {
		cin >> x;
		pieces[x]++;
	}
	int boards[4001] = {0};
	for (int x = 1; x < 2000; x++) {
		boards[x * 2] += pieces[x] / 2;
		for (int y = x + 1; y < 2001; y++) {
			boards[x + y] += min(pieces[x], pieces[y]);
		}
	}
	vector<pair<int, int>> reverse_boards;
	reverse_boards.reserve(4001);
	for (int x = 1; x < 4001; x++) {
		reverse_boards.push_back({boards[x], x});
	}
	sort(reverse_boards.begin(), reverse_boards.end(), greater<pair<int, int>>());
	int prev = reverse_boards[0].first;
	int ans = 0;
	for (pair<int, int> x : reverse_boards) {
		if (x.first == prev)
			ans++;
		else
			break;
	}
	cout << prev << ' ' << ans << endl;
}
