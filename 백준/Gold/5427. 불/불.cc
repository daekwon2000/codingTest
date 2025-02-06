#include<iostream>
#include<queue>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t = 0;
	cin >> t;

	while (t--) {

		int n, m;
		cin >> m >> n;

		char arr[1001][1001];
		int vis_sg[1001][1001];
		int vis_fr[1001][1001];

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				arr[i][j] = 0;
				vis_sg[i][j] = -1;
				vis_fr[i][j] = -1;
			}
		}

		int dx[4] = { 1, 0, -1, 0 };
		int dy[4] = { 0, 1, 0, -1 };

		queue<pair<int, int>> q_sg;
		queue<pair<int, int>> q_fr;

		for (int i = 0; i < n; i++) {
			string s;
			cin >> s;

			for (int j = 0; j < s.length(); j++) {
				arr[i][j] = s[j];

				if (arr[i][j] == '*') {
					vis_fr[i][j] = 0;
					q_fr.push({ i, j });
				}
				else if (arr[i][j] == '@') {
					vis_sg[i][j] = 0;
					q_sg.push({ i, j });
				}
			}
		}

		while (!q_fr.empty()) {
			pair<int, int> cur = q_fr.front();
			q_fr.pop();

			for (int dir = 0; dir < 4; dir++) {
				int x = cur.first + dx[dir];
				int y = cur.second + dy[dir];

				if (x < 0 || x >= n || y < 0 || y >= m) {
					continue;
				}
				if (arr[x][y] == '#' || vis_fr[x][y] > -1) {
					// 벽이거나, 방문을 했었다면
					continue;
				}

				vis_fr[x][y] = vis_fr[cur.first][cur.second] + 1;
				q_fr.push({ x, y });
			}
		}

		int pos = 0;

		while (!q_sg.empty()) {
			pair<int, int> cur = q_sg.front();
			q_sg.pop();

			for (int dir = 0; dir < 4; dir++) {
				int x = cur.first + dx[dir];
				int y = cur.second + dy[dir];

				if (x < 0 || x >= n || y < 0 || y >= m) {
					cout << vis_sg[cur.first][cur.second] + 1 << "\n";
					pos = 1;
					break;
				}
				if (arr[x][y] != '.' || vis_sg[x][y] > -1) {
					// 갈 수 있는 곳이 아니거나 (벽이거나 불이거나 나 자신)
					// 이미 방문했던 곳이라면
					continue;
				}
				if (vis_fr[x][y] != -1 && vis_fr[x][y] <= vis_sg[cur.first][cur.second] + 1) {
					// 다음 번에 내가 가려는 곳에 불이 도착하는 시간이
					// (현재 나의 시간 + 1) 한 것과 같거나 작으면 갈 수 없음!
					continue;
				}

				vis_sg[x][y] = vis_sg[cur.first][cur.second] + 1;
				q_sg.push({ x, y });
			}

			if (pos == 1) {
				break;
			}
		}

		//cout << "\n";
		//for (int i = 0; i < n; i++) {
		//	for (int j = 0; j < m; j++) {
		//		cout << vis_fr[i][j] << " ";
		//	}
		//	cout << "  ";
		//	for (int j = 0; j < m; j++) {
		//		cout << vis_sg[i][j] << " ";
		//	}
		//	cout << "\n";
		//}
		//cout << "\n";

		if (pos == 0) {
			cout << "IMPOSSIBLE\n";
		}
	}
}