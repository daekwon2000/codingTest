#include<iostream>

using namespace std;

int arr[102][102];
string s;

bool check(int x, int y, int n) {
	for (int i = x; i < x + n; i++) {
		for (int j = y; j < y + n; j++) {
			if (arr[x][y] != arr[i][j]) {
				return false;
			}
		}
	}

	return true;
}

void solve(int x, int y, int z) {
	if (check(x, y, z)) {
		s.push_back(arr[x][y] + '0');
		return;
	}

	int n = z / 2;
	s.push_back('(');
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			solve(x + i * n, y + j * n, n);
		}
	}
	s.push_back(')');
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n = 0;
	cin >> n;

	for (int i = 0; i < n; i++) {
		string tmp;
		cin >> tmp;
		for (int j = 0; j < n; j++) {
			arr[i][j] = tmp[j] - '0';
		}
	}

	solve(0, 0, n);

	cout << s << "\n";
}