#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	// If the sum of the array is an odd number, it is not possible to split it into 2 equal sets
	if ((int)((n + 1) * (n / 2.)) % 2) {
		cout << "NO\n";
	} else {
		// Define left and right bounds for first set (inclusive on both sides)
		long long lb, rb;
		if (n % 2) {
			// If the array is odd, the first element in the set will be ceil(n / 4)
			lb = ceil(n / 4.);
			// And the last element will be n - lb
			rb = n - lb;
		} else {
			// If the array is even, the first element in the set will be n / 4 + 1
			lb = n / 4 + 1;
			// And the last element will be n - lb + 1
			rb = n - lb + 1;
		}
		// If the array can't be split that way, it can't be split (I can't prove this mathematically so you'll just have to trust me)
		// So check if the array can be split that way. To do that we use Gauss' formula for sum of an arithmetic series
		// We take the sum of everything up to and including the right bound and subtract the sum of everything up to but not including the left boundary.
		// After doing that, we should get the sum of everything between (and including) the left and right boundaries
		// We double that number and compare it with the sum of the array. If they are equal, that's our solution, and if not, there is no solution
		if ((long long)(((rb + 1) * (rb / 2.)) - (long long)(lb * ((lb - 1) / 2.))) * 2 != (long long)((n + 1) * (n / 2.))) {
			cout << "NO\n";
		} else {
			cout << "YES\n" << ceil(n / 2.) << '\n';
			for (int i = lb; i < rb; i++) {
				cout << i << ' ';
			}
			cout << rb << '\n' << n / 2 << '\n';
			for (int i = 1; i < lb; i++) {
				cout << i << ' ';
			}
			for (int i = rb + 1; i < n; i++) {
				cout << i << ' ';
			}
			cout << n << endl;
		}
	}
	return 0;
}
