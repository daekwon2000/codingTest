#include<iostream>
#include<queue>

using namespace std;

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	int arr[501][501];
	int vis[501][501];

	int dx[4] = { 1,0,-1,0 };
	int dy[4] = { 0,1,0,-1 };

	queue<pair<int, int>> q;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			arr[i][j] = 0;
			vis[i][j] = 0;
		}
	}

	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;

		for (int j = 0; j < m; j++) {
			arr[i][j] = s[j] - '0'; // 입력으로 0과 1만 들어온다는 가정
		}
	}

	vis[0][0] = 1;
	q.push({ 0,0 });

	while (!q.empty()) {
		pair<int, int> cur = q.front();
		q.pop();

		for (int dir = 0; dir < 4; dir++) {
			int x = cur.first + dx[dir];
			int y = cur.second + dy[dir];

			if (x < 0 || x >= n || y < 0 || y >= m) {
				continue;
			}
			if (arr[x][y] == 0 || vis[x][y] != 0) {
				continue;
			}

			vis[x][y] = vis[cur.first][cur.second] + 1;
			q.push({ x, y });
		}
	}

	//cout << "\n\n";

	//for (int i = 0; i < n; i++) {
	//	for (int j = 0; j < m; j++) {
	//		cout << vis[i][j] << " ";
	//	}
	//	cout << "\n";
	//}

	cout << vis[n - 1][m - 1] << "\n";
}