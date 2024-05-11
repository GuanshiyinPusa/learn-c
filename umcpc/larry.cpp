#include <bits/stdc++.h>
#define L(i, j, k) for (int i = (j); i <= (k); ++i)
#define R(i, j, k) for (int i = (j); i >= (k); --i)
#define ll long long
#define sz(a) ((int)(a).size())
#define vi vector<int>
#define me(a, x) memset(a, x, sizeof(a))
#define ull unsigned long long
#define ld __float128
#define pb emplace_back
using namespace std;
#define i128 __int128

void Main() {}

int main() {
	ios ::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	long double n, a, c, b, d;
	cin >> n >> a >> c >> b >> d;

	if (a == (long double)0 && b == (long double)0) {
		cout << -1;
		return 0;
	}
	// if a = 0, b not = 0
	if (a == (long double)0 && b != (long double)0) {
		cout << -1;
		return 0;
	}

	if (a != (long double)0 && b == (long double)0) {
		if (a * n * n < d) {
			cout << -1;
			return 0;
		} else {
			cout << 0;
			return 0;
		}
	}
	cout << n * b / (a + b);
	return 0;
}
