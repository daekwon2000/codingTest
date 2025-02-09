#include<iostream>
#include<queue>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n = 0;
	cin >> n;

	int arr[102][102];
	int vis[102][102];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			arr[i][j] = 0;
			vis[i][j] = 0;
		}
	}

	int dx[4] = { 1, 0, -1, 0 };
	int dy[4] = { 0, 1, 0, -1 };

	queue<pair<int, int>> q;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}

	// 1. 각 섬을 구분하는 BFS
	
	int num = 0; // 섬의 번호
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] == 0 || vis[i][j] > 0) {
				continue;
			}

			num++;
			arr[i][j] = num;
			vis[i][j] = 1;
			q.push({ i, j });

			while (!q.empty()) {
				pair<int, int> cur = q.front();
				q.pop();

				for (int dir = 0; dir < 4; dir++) {
					int x = cur.first + dx[dir];
					int y = cur.second + dy[dir];

					if (x < 0 || x >= n || y < 0 || y >= n) {
						continue;
					}
					if (arr[x][y] == 0 || vis[x][y] > 0) {
						// 바다이거나, 이미 방문을 했다면
						continue;
					}

					arr[x][y] = num;
					vis[x][y] = 1;
					q.push({ x, y });
				}
			}
		}
	}

	// vis 배열 초기화
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			vis[i][j] = 0;
		}
	}

	// 2. 최단 경로 측정 BFS
	int ans = 100000000;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] > 0) {
				continue;
			}

			// 육지 인접 여부 체크
			int nearest = 0;
			for (int dir = 0; dir < 4; dir++) {
				int x = i + dx[dir];
				int y = j + dy[dir];

				if (x < 0 || x >= n || y < 0 || y >= n) {
					continue;
				}
				if (arr[x][y] > 0) {
					nearest = arr[x][y];
					break;
				}
			}

			if (nearest == 0) {
				// 인접한 육지가 없다면
				continue;
			}

			// 인접한 육지에서 시작하는 바다라면
			vis[i][j] = 1;
			q.push({ i, j });

			int tmp = 0;

			while (!q.empty()) {
				pair<int, int> cur = q.front();
				q.pop();

				for (int dir = 0; dir < 4; dir++) {
					int x = cur.first + dx[dir];
					int y = cur.second + dy[dir];

					if (x < 0 || x >= n || y < 0 || y >= n) {
						continue;
					}
					if (vis[cur.first][cur.second] > ans) {
						continue;
					}
					if (arr[x][y] > 0 && arr[x][y] != nearest) {
						tmp = vis[cur.first][cur.second];
						if (tmp < ans) {
							ans = tmp;
						}
					}
					if (arr[x][y] == 0 && vis[x][y] == 0) {
						vis[x][y] = vis[cur.first][cur.second] + 1;
						q.push({ x, y });
					}
				}
			}

			//cout << "\n";
			//for (int i = 0; i < n; i++) {
			//	for (int j = 0; j < n; j++) {
			//		cout << vis[i][j] << " ";
			//	}
			//	cout << "\n";
			//}
			//cout << "\n\n";

			// vis 배열 초기화
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					vis[i][j] = 0;
				}
			}
		}
	}

	//cout << "\n";
	//for (int i = 0; i < n; i++) {
	//	for (int j = 0; j < n; j++) {
	//		cout << arr[i][j] << " ";
	//	}
	//	cout << "\n";
	//}
	//cout << "\n\n";


	cout << ans << "\n";
}