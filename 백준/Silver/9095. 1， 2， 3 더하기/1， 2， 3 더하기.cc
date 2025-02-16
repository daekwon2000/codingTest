#include<algorithm>
#include<iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t = 0;
	cin >> t;

	while (t--) {
		int n = 0;
		cin >> n;

		int arr[12] = {};

		arr[1] = 1;
		arr[2] = 2;
		arr[3] = 4;

		if (n < 4) {
			cout << arr[n] << "\n";
			continue;
		}

		for (int i = 4; i <= n; i++) {
			arr[i] = arr[i - 1] + arr[i - 2] + arr[i - 3];
		}

		cout << arr[n] << "\n";
	}
}