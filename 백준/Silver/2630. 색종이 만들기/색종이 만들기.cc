#include<iostream>

using namespace std;

int arr[130][130];
int ans[2];

bool check(int x, int y, int n) {
	for (int i = x; i < x + n; i++) {
		for (int j = y; j < y + n; j++) {
			if (arr[x][y] != arr[i][j]) {
				return false;
			}
		}
	}
	return true;
}

void solve(int x, int y, int z) {
	if (check(x, y, z)) {
		ans[arr[x][y]]++;
		return;
	}

	int n = z / 2;

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			solve(x + i * n, y + j * n, n);
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n = 0;
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}

	solve(0, 0, n);

	cout << ans[0] << "\n" << ans[1] << "\n";
}