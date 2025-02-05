#include<iostream>
#include<queue>

using namespace std;

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> m >> n;

	int arr[1001][1001];
	int vis[1001][1001];

	int dx[4] = { 1,0,-1,0 };
	int dy[4] = { 0,1,0,-1 };

	queue<pair<int, int>> q;

	int max = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			arr[i][j] = 0;
			vis[i][j] = 0;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}

	// 우선, 토마토가 있는 모든 칸을 queue에 넣고 vis 값 업데이트.
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == 1) {
				vis[i][j] = 1;
				q.push({ i, j });
			}
		}
	}

	while (!q.empty()) {
		pair<int, int> cur = q.front();
		q.pop();

		for (int dir = 0; dir < 4; dir++) {
			int x = cur.first + dx[dir];
			int y = cur.second + dy[dir];

			if (x < 0 || x >= n || y < 0 || y >= m) {
				continue;
			}
			if (arr[x][y] != 0 || vis[x][y] != 0) {
				continue;
			}

			arr[x][y] = 1;
			vis[x][y] = vis[cur.first][cur.second] + 1;
			q.push({ x, y });
		}
	}

	//for (int i = 0; i < n; i++) {
	//	for (int j = 0; j < m; j++) {
	//		cout << vis[i][j] << " ";
	//	}
	//	cout << "\n";
	//}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == 0) {
				cout << -1 << "\n";
				return 0;
			}

			if (vis[i][j] > max) {
				max = vis[i][j];
			}
		}
	}

	cout << max - 1 << "\n";
}