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
	}

	for (int i = 0; i < n; i++) {
		d[i] = max(0, d[i - 1]) + arr[i];
	}
	
	cout << *max_element( d, d + n ) << "\n";
}