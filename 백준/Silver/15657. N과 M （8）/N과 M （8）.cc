#include<iostream>
#include<algorithm>

using namespace std;

int n, m;

int arr[12];
int output[12];

void func(int k, int prev) {
	if (k == m) {
		for (int i = 0; i < m; i++) {
			cout << output[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = 0; i < n; i++) {
		if (prev > arr[i]) {
			continue;
		}
		output[k] = arr[i];
		func(k + 1, arr[i]);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	sort(arr, arr + n);

	func(0, 0);
}