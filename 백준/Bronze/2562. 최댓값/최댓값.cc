#include<iostream>

using namespace std;

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int max = 0;
	int idx = 0;

	for (int i = 0; i < 9; i++) {
		int temp;
		cin >> temp;

		if (temp > max) {
			max = temp;
			idx = i;
		}
	}

	cout << max << "\n" << idx + 1 << "\n";
}