#include <bits/stdc++.h>
using namespace std;

unordered_map<unsigned int, unsigned int> memo;
unsigned long long fact(unsigned int a) {
	if (a <= 1)
		return 1;
	if (memo.find(a) != memo.end())
		return memo[a];
	return (memo[a] = ((unsigned long long)a * (unsigned long long)fact(a - 1)) % 1000000007);
}

unsigned int div(unsigned long long a, unsigned long long b) {
	unsigned long long c = b;
	c = (((c * c) % 1000000007) * b) % 1000000007;
	c = (((c * c) % 1000000007) * b) % 1000000007;
	c = (c * c) % 1000000007;
	c = (((c * c) % 1000000007) * b) % 1000000007;
	c = (((c * c) % 1000000007) * b) % 1000000007;
	c = (((c * c) % 1000000007) * b) % 1000000007;
	c = (c * c) % 1000000007;
	c = (c * c) % 1000000007;
	c = (((c * c) % 1000000007) * b) % 1000000007;
	c = (((c * c) % 1000000007) * b) % 1000000007;
	c = (c * c) % 1000000007;
	c = (((c * c) % 1000000007) * b) % 1000000007;
	c = (c * c) % 1000000007;
	c = (((c * c) % 1000000007) * b) % 1000000007;
	c = (((c * c) % 1000000007) * b) % 1000000007;
	c = (c * c) % 1000000007;
	c = (c * c) % 1000000007;
	c = (((c * c) % 1000000007) * b) % 1000000007;
	c = (c * c) % 1000000007;
	c = (((c * c) % 1000000007) * b) % 1000000007;
	c = (c * c) % 1000000007;
	c = (c * c) % 1000000007;
	c = (c * c) % 1000000007;
	c = (c * c) % 1000000007;
	c = (c * c) % 1000000007;
	c = (c * c) % 1000000007;
	c = (((c * c) % 1000000007) * b) % 1000000007;
	c = (c * c) % 1000000007;
	c = (((c * c) % 1000000007) * b) % 1000000007;
	return (a * c) % 1000000007;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	unsigned int n, m;
	cin >> n >> m;
	cout << div(fact(n - 1 + m), (fact(n - 1) * fact(m)) % 1000000007) << endl;
	return 0;
}
