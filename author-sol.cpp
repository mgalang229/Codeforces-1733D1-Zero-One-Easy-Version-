#include <bits/stdc++.h>
using namespace std;

void test_case(int& tc) {
	int n;
	long long x, y;
	cin >> n >> x >> y;
	string a, b;
	cin >> a >> b;
	long long d = 0; // no. of mismatches
	for (int i = 0; i < n; i++) {
		a[i] ^= b[i]; // set bit if a[i] != b[i]
		d += a[i];
	}
	if (d % 2) { // not possible if odd mismatches
		cout << -1 << "\n";
		return;
	}
	if (d == 2) {
		int l = 0, r = 0;
		for (l = 0; !a[l]; ) { // find position of 1st set bit
			l++;
		}
		for (r = n - 1; !a[r]; ) { // find position of 2nd set bit
			r--;
		}
		// cout << l + 1 << " " << r + 1 << "\n";
		if (l + 1 == r) { // beside
			// 2y = use an auxiliary bit (far from the two bits) to change the bits
			cout << min(x, 2 * y);
		} else { // not beside
			cout << min((r - l) * x, y);
		}
	} else {
		cout << d / 2 * y; // only using the 2nd cost
	}
	cout << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int T = 1;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		test_case(tc);
	}
}
