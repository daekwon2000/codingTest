#include<iostream>
#include<algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n = 0;
	cin >> n;

	long long d[101][10];
	
	d[1][0] = 0;
	for (int i = 1; i <= 9; i++) {
		d[1][i] = 1;
	}
	
	for (int i = 2; i <= n; i++) {
		for (int j = 0; j <= 9; j++) {
			if (j == 0) {
				d[i][j] = d[i - 1][j + 1];
			}
			else if (j == 9) {
				d[i][j] = d[i - 1][j - 1];
			}
			else {
				d[i][j] = d[i - 1][j - 1] + d[i - 1][j + 1];
			}

			d[i][j] %= 1000000000;
		}
	}

	long long sum = 0;
	for (int i = 0; i <= 9; i++) {
		sum += d[n][i];
	}

	cout << sum % 1000000000 << "\n";
}