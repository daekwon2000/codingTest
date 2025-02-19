#include<iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n = 0;
	cin >> n;

	long long arr[92][92];

	arr[1][1] = 1;
	arr[1][0] = 0;

	for (int i = 2; i <= 90; i++) {
		arr[i][0] = arr[i - 1][1] + arr[i - 1][0];
		arr[i][1] = arr[i - 1][0];
	}

	cout << arr[n][0] + arr[n][1] << "\n";
}