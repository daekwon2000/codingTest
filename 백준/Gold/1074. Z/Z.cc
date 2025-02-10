#include<iostream>
#include<cmath>
using namespace std;

int func(int n, int r, int c, int base) {
	if (n == 0) {
		return base;
	}

	if (r < (int)pow(2, n) / 2) {
		if (c < (int)pow(2, n) / 2) {
			// 좌상단
			base = func(n - 1, r, c, base);
		}
		else {
			// 우상단
			base = func(n - 1, r, c - (int)pow(2, n) / 2, base + (int)pow(2, 2 * n - 2));
		}
	}
	else {
		if (c < (int)pow(2, n) / 2) {
			// 좌하단
			base = func(n - 1, r - (int)pow(2, n) / 2, c, base + 2 * (int)pow(2, 2 * n - 2));
		}
		else {
			// 우하단
			base = func(n - 1, r - (int)pow(2, n) / 2, c - (int)pow(2, n) / 2, base + 3 * (int)pow(2, 2 * n - 2));
		}
	}

	return base;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, r, c;
	cin >> n >> r >> c;

	int ans = func(n, r, c, 0);

	cout << ans << "\n";
}