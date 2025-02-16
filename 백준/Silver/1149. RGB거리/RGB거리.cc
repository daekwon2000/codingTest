#include<iostream>
#include<algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n = 0;
	cin >> n;

	// 1000개의 집, RGB 가격
	int price[1001][3];

	// 집 번호, 이전 집의 색, 내가 선택한 집의 색
	int mn[1001][3][3];

	for (int i = 0; i < n; i++) {
		cin >> price[i + 1][0] >> price[i + 1][1] >> price[i + 1][2];
	}

	mn[1][0][1] = price[1][1];
	mn[1][0][2] = price[1][2];

	mn[1][1][0] = price[1][0];
	mn[1][1][2] = price[1][2];

	mn[1][2][0] = price[1][0];
	mn[1][2][1] = price[1][1];

	for (int i = 2; i <= n; i++) {
		mn[i][0][1] = min(mn[i - 1][1][0], mn[i - 1][2][0]) + price[i][1];
		mn[i][0][2] = min(mn[i - 1][1][0], mn[i - 1][2][0]) + price[i][2];
		mn[i][1][0] = min(mn[i - 1][0][1], mn[i - 1][2][1]) + price[i][0];
		mn[i][1][2] = min(mn[i - 1][0][1], mn[i - 1][2][1]) + price[i][2];
		mn[i][2][0] = min(mn[i - 1][0][2], mn[i - 1][1][2]) + price[i][0];
		mn[i][2][1] = min(mn[i - 1][0][2], mn[i - 1][1][2]) + price[i][1];
	}

	cout << min({ mn[n][0][1], mn[n][0][2], mn[n][1][0], mn[n][1][2], mn[n][2][0], mn[n][2][1] }) << "\n";
}