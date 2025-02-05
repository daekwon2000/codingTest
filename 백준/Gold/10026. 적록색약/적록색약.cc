#include<iostream>
#include<queue>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n = 0;
	cin >> n;

	char arr[101][101];
	int vis_bw[101][101];
	int vis_cl[101][101];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			arr[i][j] = 0;
			vis_bw[i][j] = -1;
			vis_cl[i][j] = -1;
		}
	}

	int dx[4] = { 1,0,-1,0 };
	int dy[4] = { 0,1,0,-1 };

	queue<pair<int, int>> q_bw;
	queue<pair<int, int>> q_cl;

	int block_bw = 0;
	int block_cl = 0;

	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < s.length(); j++) {
			arr[i][j] = s[j];
		}
	}

	// 정상
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (vis_cl[i][j] > -1) { // 방문한 적이 있다면
				continue;
			}

			block_cl++;

			vis_cl[i][j] = 1;
			q_cl.push({ i, j });

			while (!q_cl.empty()) {
				pair<int, int> cur = q_cl.front();
				q_cl.pop();

				for (int dir = 0; dir < 4; dir++) {
					int x = cur.first + dx[dir];
					int y = cur.second + dy[dir];

					if (x < 0 || x >= n || y < 0 || y >= n) {
						continue;
					}
					if (arr[x][y] != arr[cur.first][cur.second] || vis_cl[x][y] > -1) { 
						// 원래 위치 색상과 다른 색상이거나, 방문 기록이 있을 경우
						continue;
					}

					vis_cl[x][y] = vis_cl[cur.first][cur.second] + 1;
					q_cl.push({ x, y });
				}
			}
		}
	}

	// 적록색약
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (vis_bw[i][j] > -1) { // 방문한 적이 있다면
				continue;
			}

			block_bw++;

			vis_bw[i][j] = 1;
			q_bw.push({ i, j });

			while (!q_bw.empty()) {
				pair<int, int> cur = q_bw.front();
				q_bw.pop();

				for (int dir = 0; dir < 4; dir++) {
					int x = cur.first + dx[dir];
					int y = cur.second + dy[dir];

					if (x < 0 || x >= n || y < 0 || y >= n) {
						continue;
					}
					if (arr[cur.first][cur.second] == 'B') {
						if (arr[x][y] != arr[cur.first][cur.second] || vis_bw[x][y] > -1) {
							// R, G이거나 방문을 했었다면
							continue;
						}
					}
					else {
						if (arr[x][y] == 'B' || vis_bw[x][y] > -1) {
							// B 이거나 방문을 했었다면
							continue;
						}
					}

					vis_bw[x][y] = vis_bw[cur.first][cur.second] + 1;
					q_bw.push({ x, y });
				}
			}
		}
	}

	//for (int i = 0; i < n; i++) {
	//	for (int j = 0; j < n; j++) {
	//		cout << vis_cl[i][j] << " ";
	//	}
	//	cout << "\n";
	//}
	//cout << "\n\n";

	//for (int i = 0; i < n; i++) {
	//	for (int j = 0; j < n; j++) {
	//		cout << vis_bw[i][j] << " ";
	//	}
	//	cout << "\n";
	//}
	//cout << "\n\n";

	cout << block_cl << "\n" << block_bw << "\n";
}