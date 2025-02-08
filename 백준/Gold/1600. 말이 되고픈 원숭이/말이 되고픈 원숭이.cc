#include<iostream>
#include<queue>
#include<tuple>

using namespace std;

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int k, n, m;
	cin >> k >> m >> n;

	int arr[201][201];
	int vis[201][201][32];

	int dx[4] = { 1, 0, -1, 0 };
	int dy[4] = { 0, 1, 0, -1 };
	int dl[8] = { 1, 2, 1, 2, -1, -2, -1, -2 };
	int dr[8] = { 2, 1, -2, -1, 2, 1, -2, -1 };

	queue<tuple<int, int, int>> q;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			arr[i][j] = 0;
			for (int l = 0; l <= k; l++) {
				vis[i][j][l] = -1;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i <= k; i++) {
		vis[0][0][i] = 0;
	}

	q.push({ 0,0,0 });

	while (!q.empty()) {
		int x, y, cnt;
		tie(x, y, cnt) = q.front();
		q.pop();

		for (int dir = 0; dir < 4; dir++) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];

			if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
				continue;
			}
			if (arr[nx][ny] == 1 || vis[nx][ny][cnt] > -1) {
				// 해당 위치가 장애물이거나, 같은 이동 횟수로 이동한 적이 있다면
				continue;
			}

			/*if (arr[nx] == 0 && vis[nx][ny][cnt] > -1) {
				continue;
			}*/
			if (vis[nx][ny][cnt] == -1 || vis[x][y][cnt] + 1 < vis[nx][ny][cnt]) {
				vis[nx][ny][cnt] = vis[x][y][cnt] + 1;
				q.push({ nx, ny, cnt });
			}
		}

		for (int dir = 0; dir < 8; dir++) {
			int nx = x + dl[dir];
			int ny = y + dr[dir];

			if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
				continue;
			}
			if (arr[nx][ny] == 1 || vis[nx][ny][cnt] > -1) {
				continue;
			}
			if (cnt > k) {
				continue;
			}

			if (vis[nx][ny][cnt + 1] == -1 || vis[x][y][cnt] + 1 < vis[nx][ny][cnt + 1]) {
				vis[nx][ny][cnt + 1] = vis[x][y][cnt] + 1;
				q.push({ nx, ny, cnt + 1 });
			}
		}
	}

	//cout << "\n";
	//for (int i = 0; i < n; i++) {
	//	for (int j = 0; j < m; j++) {
	//		cout << vis[i][j][0] << " ";
	//	}
	//	cout << "\n";
	//}
	//cout << "\n\n";
	//for (int i = 0; i < n; i++) {
	//	for (int j = 0; j < m; j++) {
	//		cout << vis[i][j][1] << " ";
	//	}
	//	cout << "\n";
	//}

	int val = 0;
	int min = 100000000;

	for (int i = 0; i <= k; i++) {
		if (vis[n - 1][m - 1][i] != -1 && min > vis[n - 1][m - 1][i]) {
			min = vis[n - 1][m - 1][i];
			val = 1;
		}
	}

	if (val == 1) {
		cout << min << "\n";

	}
	else {
		cout << -1 << "\n";
	}
}