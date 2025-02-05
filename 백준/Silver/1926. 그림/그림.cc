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

	int dx[4] = {1,0,-1,0};
	int dy[4] = {0,1,0,-1};

	queue<pair<int, int>> q;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			arr[i][j] = 0;
			vis[i][j] = 0;

			int tmp;
			cin >> tmp;

			arr[i][j] = tmp;
		}
	}

	int block = 0;
	int max = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (vis[i][j] != 0 || arr[i][j] == 0) {
				continue;
			}

			block++;

			vis[i][j]++;
			q.push({i,j});

			int tmp_max = 1;

			while (!q.empty()) {
				pair<int, int> cur = q.front();
				q.pop();

				for (int k = 0; k < 4; k++) {
					int x = cur.first + dx[k];
					int y = cur.second + dy[k];

					if (x < 0 || y < 0 || x >= n || y >= m) {
						continue;
					}
					if (vis[x][y] != 0 || arr[x][y] == 0) {
						continue;
					}
					
					vis[x][y] = vis[cur.first][cur.second] + 1;
					q.push({x, y});

					tmp_max++;
				}
			}

			if (tmp_max > max) {
				max = tmp_max;
			}
		}
	}

	//cout << "\n\n";

	//for (int i = 0; i < n; i++) {
	//	for (int j = 0; j < m; j++) {
	//		cout << vis[i][j] << " ";
	//	}
	//	cout << "\n";
	//}
	
	cout << block << "\n" << max << "\n";
}