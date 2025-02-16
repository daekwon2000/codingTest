#include<iostream>
#include<algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	int arr[100002] = {};
	int sum[100002] = {};

	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}

	sum[1] = arr[1];
	sum[2] = arr[1] + arr[2];
	
	for (int i = 3; i <= 100000; i++) {
		sum[i] = sum[i - 1] + arr[i];
	}

	while (m--) {
		int i, j;
		cin >> i >> j;

		cout << sum[j] - sum[i - 1] << "\n";
	}
}