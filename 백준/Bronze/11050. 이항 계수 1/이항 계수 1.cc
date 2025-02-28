#include<iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	cin >> n >> k;

	int arr[12][12];

	arr[0][0] = 1;
	arr[1][0] = 1;
	arr[1][1] = 1;

	for (int i = 2; i < 12; i++) {
		arr[i][0] = 1;
		arr[i][i] = 1;
		for (int j = 1; j < i; j++) {
			arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
		}
	}

	cout << arr[n][k] << "\n";

}