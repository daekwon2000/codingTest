#include<iostream>

using namespace std;

char arr[4000][8000];

// 삼각형의 최상단의 좌표부터 별을 찍는 재귀 함수
void star(int x, int y, int z) {
	if (z == 3) {
		for (int i = x; i < x + 3; i++) {
			for (int j = y - 2; j < y + 3; j++) {
				if (i == x + 1 && j == y) {
					continue;
				}
				else if (i == x) {
					arr[i][y] = '*';
					continue;
				}
				else if (i == x + 1) {
					arr[i][y - 1] = '*';
					arr[i][y + 1] = '*';
					continue;
				}
				else if (i == x + 2) {
					arr[i][j] = '*';
				}
			}
		}

		return;
	}

	int n = z / 2;

	/*for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			star()
		}
	}*/

	star(x, y, n);
	star(x + n, y - n, n);
	star(x + n, y + n, n);
}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int N = 0;
	cin >> N;

	/*for (int i = 0; i < N; i++) {
		for (int j = 0; j < 2 * N; j++) {
			arr[i][j] = '';
		}
	}*/

	// 최상단의 좌표를 넘겨줌
	star(0, N - 1, N);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 2 * N - 1; j++) {
			if (arr[i][j] == '*') {
				cout << arr[i][j];
			}
			else {
				cout << ' ';
			}
		}
		cout << "\n";
	}
	cout << "\n";
}