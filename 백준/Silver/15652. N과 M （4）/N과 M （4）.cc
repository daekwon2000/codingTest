#include<iostream>

using namespace std;

int n, m;

int arr[12];

void func(int k) {
	if (k == m) {
		for (int i = 0; i < m; i++) {
			cout << arr[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = 0; i < n; i++) {
		if (k > 0) {
			if (arr[k - 1] > i + 1) {
				continue;
			}
		}

		arr[k] = i + 1;
		func(k + 1);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	func(0);
}