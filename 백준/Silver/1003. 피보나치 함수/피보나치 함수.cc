#include<iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t = 0;
	cin >> t;

	int arr0[41] = {};
	int arr1[41] = {};

	arr0[0] = 1;
	arr0[1] = 0;
	arr0[2] = 1;
	arr0[3] = 1;

	arr1[0] = 0;
	arr1[1] = 1;
	arr1[2] = 1;
	arr1[3] = 2;

	for (int i = 4; i <= 40; i++) {
		arr0[i] = arr0[i - 1] + arr0[i - 2];
		arr1[i] = arr1[i - 1] + arr1[i - 2];
	}

	while (t--) {
		int n = 0;
		cin >> n;

		cout << arr0[n] << " " << arr1[n] << "\n";
	}
}