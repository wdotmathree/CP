/*
	Since we only care about compressing the least amount of songs possible, we can greedily select the songs
	We sort the list of songs based on bytes saved by compressing it in descending order
		i.e. The song that will save the most space when compressed goes first
	Set the default ans to -1 as if it is impossible to fit all the songs on the flash drive the ans will not be modified
	First check if the songs can fit without compression and if it can, set the ans to 0
	If songs have to be compressed, iterate through the list of songs and compress each one until under the storage limit
	Keep track of how many songs have been compressed and once under the storage limit, set ans to the number of songs compressed
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin >> n >> m;
	pair<int, int> songs[n];
	unsigned long long sum = 0;
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		songs[i] = {x, y};
		sum += x;
	}
	sort(songs, songs + n, [](pair<int, int> a, pair<int, int> b) { return a.first - a.second > b.first - b.second; });
	int ans = -1;
	if (sum <= m) {
		ans = 0;
	} else {
		for (int i = 1; i <= n; i++) {
			sum -= songs[i - 1].first - songs[i - 1].second;
			if (sum <= m) {
				ans = i;
				break;
			}
		}
	}
	cout << ans << endl;
	return 0;
}
