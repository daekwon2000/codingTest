#include<iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int arr[21];

	for (int i = 1; i < 21; i++) {
		arr[i] = i;
	}

	for (int i = 0; i < 10; i++) {

		int a, b;
		cin >> a >> b;

		int temp[21];

		for (int j = b; j >= a; j--) {
			temp[b - j + a] = arr[j];
		}

		for (int j = a; j <= b; j++) {
			arr[j] = temp[j];
		}
	}

	for (int i = 1; i <= 20; i++) {
		cout << arr[i] << " ";
	}
}