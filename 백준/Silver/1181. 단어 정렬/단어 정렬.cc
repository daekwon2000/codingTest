#include<iostream>
#include<algorithm>

using namespace std;

bool cmp(string& a, string& b) {
	int lenA = a.length();
	int lenB = b.length();

	if (lenA < lenB) {
		return true;
	}
	else if (lenA == lenB) {
		if (a < b) {
			return true;
		}
		return false;
	}
	return false;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n = 0;
	cin >> n;

	string arr[20002];

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	sort(arr, arr + n, cmp);

	string tmp = arr[0];

	cout << arr[0] << "\n";

	for (int i = 1; i < n; i++) {
		if (arr[i] == tmp) {
			continue;
		}
		tmp = arr[i];
		cout << arr[i] << "\n";
	}
}