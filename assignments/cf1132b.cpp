/*
	The most optimal way to use a coupon is to purchase the most expensive items with that coupon
	In that case, the least expensive of the group will be given for free
	For example:
		If you have a coupon that lets you buy 3 and pay for 2, the most optimal way to use it would be to buy the most
		Expensive 3 chocolate bars and the 3rd most expensive one will be given for free
	With this observation, we know that the optimal price for each coupon is the sum of all chocolate bars minus the cost of
	The q-th most expensive one, which will be in index q - 1 due to the list being sorted in descending order
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		a[i] = x;
	}
	int m;
	cin >> m;
	int q[m];
	for (int i = 0; i < m; i++) {
		int x;
		cin >> x;
		q[i] = x;
	}
	sort(a, a + n, [](const int a, const int b) { return a > b; });
	unsigned long long sum = 0;
	for (int i = 0; i < n; i++) {
		sum += a[i];
	}
	for (int i = 0; i < m; i++) {
		cout << sum - a[q[i] - 1] << '\n';
	}
	return 0;
}
