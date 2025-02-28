#include<iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	cin >> n >> k;

	int arr[1002][1002];

	arr[0][0] = 1;
	arr[1][0] = 1;
	arr[1][1] = 1;

	for (int i = 2; i < 1002; i++) {
		arr[i][0] = 1;
		arr[i][i] = 1;
		for (int j = 1; j < i; j++) {
			arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
			arr[i][j] %= 10007;
		}
	}

	//for (int i = 0; i < 102; i++) {
	//	for (int j = 0; j < 102; j++) {
	//		cout << arr[i][j] << " ";
	//	}
	//	cout << "\n";
	//}
	//cout << "\n";

	cout << arr[n][k] << "\n";

}