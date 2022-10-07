#include <bits/stdc++.h>
using namespace std;

unordered_map<unsigned int, unsigned int> memo;
unsigned int fact(unsigned int a) {
	if (a <= 1)
		return 1;
	if (memo.find(a) != memo.end())
		return memo[a];
	return (memo[a] = a * fact(a - 1));
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string s;
	cin >> s;
	sort(s.begin(), s.end());
	int n = fact(s.size());
	int a[26] = {0};
	for (int i = 0; i < s.size(); i++) {
		a[s[i] - 'a']++;
	}
	for (int i = 0; i < 26; i++) {
		n /= fact(a[i]);
	}
	cout << n << '\n';
	do {
		cout << s << '\n';
	} while (next_permutation(s.begin(), s.end()));
	return 0;
}
