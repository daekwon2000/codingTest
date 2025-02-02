#include<iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n = 0;
	int k = 0;

	cin >> n >> k;

	int arr[6][2] = {};

	for (int i = 0; i < n; i++) {
		int s, y;
		cin >> s >> y;

		arr[y - 1][s]++;
	}

	int room = 0;

	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 2; j++) {
			if (arr[i][j] % k == 0) {
				room += arr[i][j] / k;
			}
			else {
				room += arr[i][j] / k + 1;
			}
		}
	}

	cout << room << "\n";
}