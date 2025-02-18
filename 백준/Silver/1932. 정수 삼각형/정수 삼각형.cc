#include<iostream>
#include<algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n = 0;
	cin >> n;

	int arr[501][501];
	int sum[501][501];

	for (int i = 0; i < 501; i++) {
		for (int j = 0; j < 501; j++) {
			arr[i][j] = 0;
			sum[i][j] = 0;
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			cin >> arr[i][j];
		}
	}

	sum[1][1] = arr[1][1];

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			// index를 체크하는 과정을 추가해야하나 고민했으나,
			// 1-indexed array로 설정하고 가장자리의 값에는 0을 넣어
			// max 함수에서 선택되지 않도록 하였음.
			// (값의 범위가 0~9999 여서 가능)
			sum[i][j] = max(sum[i - 1][j - 1], sum[i - 1][j]) + arr[i][j];
		}
	}

	int mx = 0;
	for (int i = 1; i <= n; i++) {
		if (sum[n][i] > mx) {
			mx = sum[n][i];
		}
	}

	cout << mx << "\n";

}