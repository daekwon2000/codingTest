#include<iostream>

using namespace std;

int n, m;

int arr[12];
int isUsed[12];

void func(int k) {
	if (k == m) {
		for (int i = 0; i < m; i++) {
			cout << arr[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = 0; i < n; i++) {
		// isUsed를 쓸 일이 없다..!
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