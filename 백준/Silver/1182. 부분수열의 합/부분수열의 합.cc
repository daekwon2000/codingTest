#include<iostream>

using namespace std;

int n, s;

int arr[22];
// int output[22];
// int isUsed[22];

int cnt = 0;

void func(int k, int sum) {
	if (k == n) {
		if (sum == s) {
			cnt++;
			return;
		}
		return;
	}
	
	
	func(k + 1, sum);
	func(k + 1, sum + arr[k]);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> s;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	func(0, 0);

	if (s == 0) {
		// 공집합 제외
		cnt--;
	}

	cout << cnt << "\n";
}