#include<iostream>

using namespace std;

char arr[2200][2200];

void spacing(int x, int y, int z) {
	for (int i = x; i < x + z; i++) {
		for (int j = y; j < y + z; j++) {
			arr[i][j] = ' ';
		}
	}
}

void star(int x, int y, int z) {
	if (z == 3) {
		for (int i = x; i < x + 3; i++) {
			for (int j = y; j < y + 3; j++) {
				if (i == x + 1 && j == y + 1) {
					spacing(i, j, 1);
					continue;
				}
				arr[i][j] = '*';
			}
		}
		return;
	}

	int n = z / 3;

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (i == 1 && j == 1) {
				spacing(x + n, y + n, n);
				continue;
			}
			star(x + i * n, y + j * n, n);
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N = 0;
	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			arr[i][j] = ' ';
		}
	}

	star(0, 0, N);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << arr[i][j];
		}
		cout << "\n";
	}
	cout << "\n";
}