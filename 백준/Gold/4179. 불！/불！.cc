#include<iostream>
#include<queue>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	int arr[1001][1001];
	int vis_jh[1001][1001];
	int vis_fr[1001][1001];

	int dx[4] = { 1,0,-1,0 };
	int dy[4] = { 0,1,0,-1 };

	queue<pair<int, int>> q_jh;
	queue<pair<int, int>> q_fr;

	pair<int, int> jh;
	pair<int, int> fr;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			arr[i][j] = 0;
			vis_jh[i][j] = 0;
			vis_fr[i][j] = 0;
		}
	}

	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < m; j++) {
			if (s[j] == '#') {
				arr[i][j] = -1;
			}
			else if (s[j] == 'J') {
				arr[i][j] = 1;
				jh = { i, j };
			}
			else if (s[j] == 'F') {
				arr[i][j] = -2;
				q_fr.push({ i, j });
				vis_fr[i][j] = 1;
				//fr = { i, j };
			}
			else {
				arr[i][j] = 0;
			}
		}
	}

	vis_jh[jh.first][jh.second] = 1;
	//vis_fr[fr.first][fr.second] = 1;

	q_jh.push(jh);
	q_fr.push(fr);

	while (!q_fr.empty()) {
		pair<int, int> cur = q_fr.front();
		q_fr.pop();

		for (int dir = 0; dir < 4; dir++) {
			int x = cur.first + dx[dir];
			int y = cur.second + dy[dir];

			if (x < 0 || x >= n || y < 0 || y >= m) {
				continue;
			}
			if (arr[x][y] == -1 || vis_fr[x][y] != 0) {
				continue;
			}

			vis_fr[x][y] = vis_fr[cur.first][cur.second] + 1;
			q_fr.push({ x, y });
		}
	}

	while (!q_jh.empty()) {
		pair<int, int> cur = q_jh.front();
		q_jh.pop();

		for (int dir = 0; dir < 4; dir++) {
			int x = cur.first + dx[dir];
			int y = cur.second + dy[dir];

			if (x < 0 || x >= n || y < 0 || y >= m) {
				cout << vis_jh[cur.first][cur.second] << "\n";
				return 0;
			}
			if (arr[x][y] != 0 || vis_jh[x][y] != 0) {
				continue;
			}
			if( vis_fr[x][y] != 0 && vis_fr[x][y] <= vis_jh[cur.first][cur.second] + 1) {
				continue;
			}

			vis_jh[x][y] = vis_jh[cur.first][cur.second] + 1;
			q_jh.push({ x, y });
		}
	}


	cout << "IMPOSSIBLE\n";
	
	//q.push(jh);
	//q.push(fr);
	//q.push(jh);

	// 지훈이와 불이 순차적으로 큐에 들어감..?

	//while (!q.empty()) {

	//	//cout << "\n\n";
	//	//for (int i = 0; i < n; i++) {
	//	//	for (int j = 0; j < m; j++) {
	//	//		cout << vis_jh[i][j] << " ";
	//	//	}
	//	//	cout << " ";
	//	//	for (int j = 0; j < m; j++) {
	//	//		cout << vis_fr[i][j] << " ";
	//	//	}
	//	//	cout << " ";
	//	//	for (int j = 0; j < m; j++) {
	//	//		cout << arr[i][j] << " ";
	//	//	}
	//	//	cout << "\n";
	//	//}

	//	pair<int, int> cur = q.front();
	//	q.pop();

	//	if (arr[cur.first][cur.second] == -1) { // 불
	//		for (int dir = 0; dir < 4; dir++) {
	//			int x = cur.first + dx[dir];
	//			int y = cur.second + dy[dir];

	//			if (x < 0 || x >= n || y < 0 || y >= m) {
	//				continue;
	//			}
	//			if (arr[x][y] == -1 || vis_fr[x][y] != 0) {
	//				continue;
	//			}

	//			vis_fr[x][y] = vis_fr[cur.first][cur.second] + 1;
	//			//arr[x][y] = -1;
	//			q.push({ x, y });
	//		}
	//	}
	//	else { // 지훈
	//		for (int dir = 0; dir < 4; dir++) {
	//			int x = cur.first + dx[dir];
	//			int y = cur.second + dy[dir];

	//			if (x < 0 || x >= n || y < 0 || y >= m) {
	//				//continue;
	//				cout << vis_jh[cur.first][cur.second] << "\n";
	//				return 0;
	//			}
	//			if (arr[x][y] == -1 || vis_jh[x][y] != 0) {
	//				continue;
	//			}

	//			vis_jh[x][y] = vis_jh[cur.first][cur.second] + 1;
	//			arr[x][y] = 1;
	//			q.push({ x, y });
	//		}
	//	}
	//}
}