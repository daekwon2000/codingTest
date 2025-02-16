#include<iostream>
#include<algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n = 0;
	cin >> n;

	int stair[301] = {};

	for (int i = 0; i < n; i++) {
		cin >> stair[i + 1];
	}

	int score[301][3];
	
	score[0][0] = 0;
	score[0][1] = 0;
	score[0][2] = 0;

	score[1][1] = stair[1];
	score[2][1] = stair[2];
	score[2][2] = stair[1] + stair[2];

	for (int i = 3; i <= n; i++) {
		score[i][1] = max(score[i - 2][1], score[i - 2][2]);
		score[i][1] += stair[i];

		score[i][2] = score[i - 1][1] + stair[i];
	}

	cout << max(score[n][1], score[n][2]);
}