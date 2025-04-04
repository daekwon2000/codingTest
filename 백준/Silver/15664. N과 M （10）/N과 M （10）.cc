#include<iostream>
#include<algorithm>

using namespace std;

int n, m;

int arr[12];
int output[12];
int isUsed[12];

void func(int k, int prev) {
	if (k == m) {
		for (int i = 0; i < m; i++) {
			cout << output[i] << " ";
		}
		cout << "\n";
		return;
	}

	int tmp = 0;
	for (int i = 0; i < n; i++) {
		if (isUsed[i] == 0) {
			if (tmp == arr[i] || arr[i] < prev) {
				continue;
			}
			isUsed[i] = 1;
			output[k] = arr[i];
			tmp = arr[i];
			func(k + 1, arr[i]);
			isUsed[i] = 0;
		}
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