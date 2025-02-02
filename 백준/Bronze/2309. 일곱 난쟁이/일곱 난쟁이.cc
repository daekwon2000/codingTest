#include<iostream>
#include<algorithm>

using namespace std;

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int arr[9];

	int sum = 0;

	int a, b;

	for (int i = 0; i < 9; i++) {
		cin >> arr[i];
		sum = sum + arr[i];
	}

	sort(arr, arr + 9);

	for (int i = 0; i < 8; i++) {
		for (int j = i + 1; j < 9; j++) {
			if (arr[i] + arr[j] == sum - 100) {
				a = i;
				b = j;
				break;
			}
		}
	}

	for (int i = 0; i < 9; i++) {
		if (i != a && i != b) {
			cout << arr[i] << "\n";
		}
	}
}