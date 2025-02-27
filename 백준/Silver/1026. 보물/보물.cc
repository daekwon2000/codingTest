#include<iostream>
#include<algorithm>

using namespace std;

bool cmp(int a, int b) {
	if (a > b) {
		return true;
	}
	return false;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n = 0;
	cin >> n;

	int arrA[1002] = {};
	int arrB[1002] = {};
	int arrS[1002] = {};

	for (int i = 0; i < n; i++) {
		cin >> arrA[i];
	}

	for (int i = 0; i < n; i++) {
		cin >> arrB[i];
	}

	sort(arrA, arrA + n);
	sort(arrB, arrB + n, cmp);
	
	long long sum = 0;
	for (int i = 0; i < n; i++) {
		sum += arrA[i] * arrB[i];
	}

	cout << sum << "\n";
}