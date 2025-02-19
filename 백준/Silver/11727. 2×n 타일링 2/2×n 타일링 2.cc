#include<iostream>
#include<algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n = 0;
	cin >> n;

	int arr[1001] = {};

	arr[1] = 1;
	arr[2] = 3;

	for (int i = 3; i <= 1000; i++) {
		arr[i] = arr[i - 1] + 2 * arr[i - 2];
		arr[i] %= 10007;
	}

	cout << arr[n] << "\n";
}