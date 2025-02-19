#include<iostream>
#include<algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n = 0;
	cin >> n;

	int term[20] = {};
	int price[20] = {};
	int d[20] = {};

	for (int i = 1; i <= n; i++) {
		cin >> term[i] >> price[i];
	}

	for (int i = n; i >= 1; i--) {
		// 남은 기간동안 일을 처리할 수 없는 경우.
		if (term[i] > n - i + 1) {
			// 그날로부터는 돈을 벌 수 없다.
			d[i] = 0;
		}
		else {
			d[i] = price[i];
		}
	}

	//for (int i = 1; i <= n; i++) {
	//	cout << d[i] << " ";
	//}
	//cout << "\n";

	for (int i = n; i >= 1; i--) {
		for (int j = n; j > i; j--) {
			if (term[i] > n - i + 1) {
				d[i] = max(d[i], d[j]);
				continue;
			}

			d[i] = max(d[i + term[i]] + price[i], d[j]);
		}
	}

	//for (int i = 1; i <= n; i++) {
	//	cout << d[i] << " ";
	//}
	//cout << "\n";

	cout << *max_element(d + 1, d + n + 1) << "\n";
}