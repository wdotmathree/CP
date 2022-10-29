#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string needle, haystack;
	cin >> needle >> haystack;
	unsigned int ncount[26];
	unsigned int hcount[26];
	memset(ncount, 0, 104);
	memset(hcount, 0, 104);
	unordered_set<unsigned int> used;
	unsigned int ans = 0;
	if (needle.length() <= haystack.length()) {
		unsigned long long hash = 0;
		unsigned long long a = 1;
		unsigned long long p = 0xfffffffb;
		int A = 43;
		for (int i = 0; i < needle.length(); i++) {
			ncount[needle[i] - 'a']++;
			hcount[haystack[i] - 'a']++;
			hash = (hash + (haystack[needle.length() - i - 1] * a) % p) % p;
			a = (a * A) % p;
		}
		a = (a * 0xe82fa0ba) % p;
		if (equal(ncount, ncount + 26, hcount)) {
			ans++;
			used.insert(hash);
		}
		for (int i = 1; i + needle.length() <= haystack.length(); i++) {
			hcount[haystack[i - 1] - 'a']--;
			hcount[haystack[i + needle.length() - 1] - 'a']++;
			hash = (A * (hash + p - (haystack[i - 1] * a) % p) % p) % p;
			hash = (hash + haystack[i + needle.length() - 1]) % p;
			if (equal(ncount, ncount + 26, hcount)) {
				if (used.find(hash) == used.end()) {
					ans++;
					used.insert(hash);
				}
			}
		}
	}
	cout << ans << endl;
	return 0;
}
