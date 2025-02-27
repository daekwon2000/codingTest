#include<iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	cin >> n >> k;

	int arr[12] = {};

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	int cnt = 0;

	for (int i = n - 1; i >= 0; i--) {
		cnt += k / arr[i];
		k %= arr[i];
	}

	cout << cnt << "\n";
}