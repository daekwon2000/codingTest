#include<iostream>
#include<tuple>

using namespace std;

int n, m;
int arr[12][12];
tuple<int, int, int> cctv_list[10];
// cctv 좌표와 종류

int blank = 0;
int cctv = 0;

int mn = 1000000000;

void change(int x, int y, int dir, bool opt) {
	if (opt == true) {
		if (dir == 1) {
			// 상
			for (int i = x; i >= 0; i--) {
				if (arr[i][y] == 6) {
					break;
				}
				if (arr[i][y] == 0) {
					arr[i][y]--;
					blank--;
				}
				else if (arr[i][y] < 0) {
					arr[i][y]--;
				}
			}
		}
		else if (dir == 2) {
			// 하
			for (int i = x; i < n; i++) {
				if (arr[i][y] == 6) {
					break;
				}
				if (arr[i][y] == 0) {
					arr[i][y]--;
					blank--;
				}
				else if (arr[i][y] < 0) {
					arr[i][y]--;
				}
			}
		}
		else if (dir == 3) {
			// 좌
			for (int i = y; i >= 0; i--) {
				if (arr[x][i] == 6) {
					break;
				}
				if (arr[x][i] == 0) {
					arr[x][i]--;
					blank--;
				}
				else if (arr[x][i] < 0) {
					arr[x][i]--;
				}
			}
		}
		else if (dir == 4) {
			// 우
			for (int i = y + 1; i < m; i++) {
				if (arr[x][i] == 6) {
					break;
				}
				if (arr[x][i] == 0) {
					arr[x][i]--;
					blank--;
				}
				else if (arr[x][i] < 0) {
					arr[x][i]--;
				}
			}
		}
	}
	else if (opt == false) {
		if (dir == 1) {
			// 상
			for (int i = x; i >= 0; i--) {
				if (arr[i][y] == 6) {
					break;
				}
				else if (arr[i][y] == -1) {
					arr[i][y]++;
					blank++;
				}
				else if (arr[i][y] < -1) {
					arr[i][y]++;
				}
			}
		}
		else if (dir == 2) {
			// 하
			for (int i = x; i < n; i++) {
				if (arr[i][y] == 6) {
					break;
				}
				else if (arr[i][y] == -1) {
					arr[i][y]++;
					blank++;
				}
				else if (arr[i][y] < -1) {
					arr[i][y]++;
				}
			}
		}
		else if (dir == 3) {
			// 좌
			for (int i = y; i >= 0; i--) {
				if (arr[x][i] == 6) {
					break;
				}
				else if (arr[x][i] == -1) {
					arr[x][i]++;
					blank++;
				}
				else if (arr[x][i] < -1) {
					arr[x][i]++;
				}
			}
		}
		else if (dir == 4) {
			// 우
			for (int i = y + 1; i < m; i++) {
				if (arr[x][i] == 6) {
					break;
				}
				else if (arr[x][i] == -1) {
					arr[x][i]++;
					blank++;
				}
				else if (arr[x][i] < -1) {
					arr[x][i]++;
				}
			}
		}
	}
	
}

void func(int k) { // k번째 cctv를 방향을 돌려가며 동작시킴
	if (k == cctv) {
		if (blank < mn) {
			mn = blank;
		}
		return;
	}

	int x, y, type;
	tie(x, y, type) = cctv_list[k];

	if (type == 1) {
		change(x, y, 1, true);
		func(k + 1);
		change(x, y, 1, false);

		change(x, y, 2, true);
		func(k + 1);
		change(x, y, 2, false);

		change(x, y, 3, true);
		func(k + 1);
		change(x, y, 3, false);

		change(x, y, 4, true);
		func(k + 1);
		change(x, y, 4, false);
	}
	else if (type == 2) {
		// 좌우로 감시
		change(x, y, 3, true);
		change(x, y, 4, true);
		func(k + 1);
		// 원상복구
		change(x, y, 3, false);
		change(x, y, 4, false);

		// 상하로 감시
		change(x, y, 1, true);
		change(x, y, 2, true);
		func(k + 1);
		// 원상복구
		change(x, y, 1, false);
		change(x, y, 2, false);
	}
	else if (type == 3) {
		// 상 우 감시
		change(x, y, 1, true);
		change(x, y, 4, true);
		func(k + 1);
		// 원상복구
		change(x, y, 1, false);
		change(x, y, 4, false);

		// 우 하 감시
		change(x, y, 2, true);
		change(x, y, 4, true);
		func(k + 1);
		// 원상복구
		change(x, y, 2, false);
		change(x, y, 4, false);

		// 하 좌 감시
		change(x, y, 2, true);
		change(x, y, 3, true);
		func(k + 1);
		// 원상복구
		change(x, y, 2, false);
		change(x, y, 3, false);

		// 좌 상 감시
		change(x, y, 1, true);
		change(x, y, 3, true);
		func(k + 1);
		// 원상복구
		change(x, y, 1, false);
		change(x, y, 3, false);
	}
	else if (type == 4) {
		// 상 빼고 감시
		change(x, y, 2, true);
		change(x, y, 3, true);
		change(x, y, 4, true);
		func(k + 1);
		// 원상복구
		change(x, y, 2, false);
		change(x, y, 3, false);
		change(x, y, 4, false);

		// 우 빼고 감시
		change(x, y, 2, true);
		change(x, y, 3, true);
		change(x, y, 1, true);
		func(k + 1);
		// 원상복구
		change(x, y, 2, false);
		change(x, y, 3, false);
		change(x, y, 1, false);

		// 하 빼고 감시
		change(x, y, 4, true);
		change(x, y, 3, true);
		change(x, y, 1, true);
		func(k + 1);
		// 원상복구
		change(x, y, 4, false);
		change(x, y, 3, false);
		change(x, y, 1, false);

		// 좌 빼고 감시
		change(x, y, 4, true);
		change(x, y, 2, true);
		change(x, y, 1, true);
		func(k + 1);
		// 원상복구
		change(x, y, 4, false);
		change(x, y, 2, false);
		change(x, y, 1, false);
	}
	else if (type == 5) {
		// 상하좌우로 감시
		change(x, y, 1, true);
		change(x, y, 2, true);
		change(x, y, 3, true);
		change(x, y, 4, true);
		func(k + 1);
		// 원상복구
		change(x, y, 1, false);
		change(x, y, 2, false);
		change(x, y, 3, false);
		change(x, y, 4, false);
	}
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	blank = n * m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
			if (arr[i][j] != 0 && arr[i][j] != 6) {
				cctv_list[cctv] = { i, j, arr[i][j] };
				cctv++;
				blank--;
			}
			else if(arr[i][j] == 6) {
				blank--;
			}
		}
	}

	// cout << blank << "\n";

	func(0);

	cout << mn << "\n";
}