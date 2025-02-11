#include<iostream>
#include<algorithm>

using namespace std;

int n, m;

int arr[12];
int output[12];
int isUsed[12];

void func(int k) {
	if (k == m) {
		for (int i = 0; i < m; i++) {
			cout << output[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = 0; i < n; i++) {
		if (isUsed[i] == 0) {
			output[k] = arr[i];
			isUsed[i] = 1;
			func(k + 1);
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

	func(0);
}