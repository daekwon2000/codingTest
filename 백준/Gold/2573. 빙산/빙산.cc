#include<iostream>
#include<queue>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	int arr[301][301];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}

	int dx[4] = { 1,0,-1,0 };
	int dy[4] = { 0,1,0,-1 };

	int year = 0;

	while (true) {
		// 1. 현재 블록 갯수 측정
		// --------------------------------------
		int block = 0;

		int vis[301][301];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				vis[i][j] = -1;
			}
		}
		queue<pair<int, int>> q;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (arr[i][j] == 0 || vis[i][j] > -1) {
					// 바다이거나 방문을 했었으면
					continue;
				}

				block++;

				vis[i][j] = 1;
				q.push({ i, j });

				while (!q.empty()) {
					pair<int, int> cur = q.front();
					q.pop();

					for (int dir = 0; dir < 4; dir++) {
						int x = cur.first + dx[dir];
						int y = cur.second + dy[dir];

						if (x < 0 || x >= n || y < 0 || y >= m) {
							continue;
						}
						if (arr[x][y] == 0 || vis[x][y] > -1) {
							continue;
						}

						vis[x][y] = vis[cur.first][cur.second] + 1;
						q.push({ x, y });
					}
				}

				
			}
		}
		if (block == 0) {
			cout << 0 << "\n";
			return 0;
		}
		if (block >= 2) {
			cout << year << "\n";
			return 0;
		}

		// 2. 빙하 녹이기
		// --------------------------------------

		int melt[301][301];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				melt[i][j] = 0;
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (arr[i][j] == 0) {
					continue;
				}

				int sea = 0;
				
				for (int dir = 0; dir < 4; dir++) {
					int x = i + dx[dir];
					int y = j + dy[dir];

					if (arr[x][y] == 0) {
						sea++;
					}
				}

				melt[i][j] = sea;
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				arr[i][j] -= melt[i][j];

				if (arr[i][j] < 0) {
					arr[i][j] = 0;
				}
			}
		}

		/*for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cout << arr[i][j] << " ";
			}
			cout << "\n";
		}
		cout << "\n\n";*/

		year++;
	}
}