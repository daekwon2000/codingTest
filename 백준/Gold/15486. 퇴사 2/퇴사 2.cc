#include<iostream>
#include<algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n = 0;
	cin >> n;

	int term[1501000] = {};
	int price[1501000] = {};
	int d[1501000] = {};

	for (int i = 1; i <= n; i++) {
		cin >> term[i] >> price[i];
	}

	for (int i = n; i >= 1; i--) {
		if (term[i] > n - i + 1) {
			d[i] = d[i + 1];
		}
		else {
			d[i] = max(d[i + term[i]] + price[i], d[i + 1]);
		}
	}

	cout << *max_element(d + 1, d + n + 1) << "\n";
}