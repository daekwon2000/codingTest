#include<iostream>
#include<algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	int arr[10];

	for (int i = 0; i < n; i++) {
		arr[i] = 1;
	}

	for (int i = 0; i < m; i++) {
		arr[i] = 0;
	}

	do {
		for (int i = 0; i < n; i++) {
			if (arr[i] == 0) {
				cout << i + 1 << " ";
			}
		}
		cout << "\n";
	} while (next_permutation(arr, arr + n));

	/*do {
		for (int i = 0; i < m; i++) {
			cout << arr[i] << " ";
		}
		cout << "\n";
	} while (next_permutation(arr, arr + n));*/
}