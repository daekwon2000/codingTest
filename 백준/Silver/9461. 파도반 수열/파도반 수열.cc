#include<iostream>
#include<algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t = 0;
	cin >> t;

	while (t--) {
		int n = 0;
		cin >> n;

		long long arr[102] = {};

		arr[1] = 1;
		arr[2] = 1;
		arr[3] = 1;

		for (int i = 4; i <= n; i++) {
			arr[i] = arr[i - 2] + arr[i - 3];
		}

		cout << arr[n] << "\n";
	}
}