#include<iostream>
#include<algorithm>

using namespace std;

bool cmp(string& a, string& b) {
	int sumA = 0;
	int sumB = 0;

	int lengthA = a.length();
	int lengthB = b.length();

	if (lengthA < lengthB) {
		return true;
	}
	else if (lengthA == lengthB) {
		for (int i = 0; i < lengthA; i++) {
			if (a[i] >= '0' && a[i] <= '9') {
				sumA += a[i] - '0';
			}
		}

		for (int i = 0; i < lengthB; i++) {
			if (b[i] >= '0' && b[i] <= '9') {
				sumB += b[i] - '0';
			}
		}

		if (sumA < sumB) {
			return true;
		}
		else if (sumA == sumB) {
			return a < b;
		}
		else {
			return false;
		}
	}
	else {
		return false;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	string arr[52];

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	sort(arr, arr + n, cmp);

	for (int i = 0; i < n; i++) {
		cout << arr[i] << "\n";
	}
}