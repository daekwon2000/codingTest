#include<iostream>
#include<queue>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t = 0;
	cin >> t;

	while (t--) {

		int n, m, k = 0;
		cin >> m >> n >> k;

		int arr[51][51];
		int vis[51][51];

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				arr[i][j] = 0;
				vis[i][j] = 0;
			}
		}

		int dx[4] = { 1, 0, -1, 0 };
		int dy[4] = { 0, 1, 0, -1 };

		int warm = 0;

		queue<pair<int, int>> q;

		for (int i = 0; i < k; i++) {
			int tmp_x, tmp_y;
			cin >> tmp_y >> tmp_x;
			arr[tmp_x][tmp_y] = 1;
		}

		for(int i = 0; i < n; i++){
			for (int j = 0; j < m; j++) {
				if (arr[i][j] == 0 || vis[i][j] > 0) { // 방문했었거나, 흙이라면
					continue;
				}

				warm++;

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
						if (vis[x][y] > 0 || arr[x][y] == 0) { // 이미 방문 했거나, 흙이라면.
							continue;
						}

						vis[x][y] = 1;
						q.push({ x, y });
					}
				}
			}
		}

		//for (int i = 0; i < n; i++) {
		//	for (int j = 0; j < m; j++) {
		//		cout << vis[i][j] << " ";
		//	}
		//	cout << "\n";
		//}

		cout << warm << "\n";
	}
}