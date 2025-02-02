#include<iostream>
#include<algorithm>

using namespace std;

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	int costant_var = n;

	int arr[10] = {};

	while (n != 0) {
		int mod = n % 10;
		arr[mod]++;
		n = n / 10;
	}

	arr[6] = arr[6] + arr[9];

	if (arr[6] % 2 == 0) {
		arr[6] = arr[6] / 2;
	}
	else {
		arr[6] = arr[6] + 1;
		arr[6] = arr[6] / 2;
	}

	int max = 0;

	for (int i = 0; i < 9; i++) {
		if (arr[i] >= max) {
			max = arr[i];
		}
	}

	cout << max << "\n";
}