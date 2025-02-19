#include<iostream>
#include<algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n = 0;
	cin >> n;

	int arr[100002] = {};
	int d[100002] = {};

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		d[i] = 1;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (arr[j] < arr[i]) {
				d[i] = max(d[i], d[j] + 1);
			}
		}
	}

	cout << *max_element(d, d + n) << "\n";
}