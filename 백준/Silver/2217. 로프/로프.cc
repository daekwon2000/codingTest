#include<iostream>
#include<algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n = 0;
	cin >> n;

	int arr[100002] = {};

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	sort(arr, arr + n);

	int mx = 0;

	for (int i = 0; i < n; i++) {
		int wt = arr[i] * (n - i);

		if (wt > mx) {
			mx = wt;
		}
	}

	cout << mx << "\n";
}