#include<iostream>

using namespace std;

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int odd[7];

	int sum = 0;
	int min = 101;

	for (int i = 0; i < 7; i++) {

		cin >> odd[i];

		if (odd[i] % 2 == 1) {
			sum = sum + odd[i];

			if (odd[i] < min) {
				min = odd[i];
			}
		}

	}


	if (sum == 0) {
		cout << -1 << "\n";
	}
	else {
		cout << sum << "\n" << min << "\n";
	}
}