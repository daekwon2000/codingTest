#include<iostream>
#include<algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n = 0;
	cin >> n;
	
	string arr[1000002] = {};
	long long output[1000002] = {};

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < n; i++) {
		long long tmp = 0;
		long long deci = 1;
		for (int j = 0; j < arr[i].length(); j++) {
			tmp += deci * (arr[i][j] - '0');
			deci *= 10;
		}
		output[i] = tmp;
	}

	sort(output, output + n);

	for (int i = 0; i < n; i++) {
		cout << output[i] << "\n";
	}
}