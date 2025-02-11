#include<iostream>

using namespace std;

int n;

int isUsed1[40];
int isUsed2[40];
int isUsed3[40];

int cnt = 0;

void func(int cur) {
	// cur은 현재 행을 의미
	// i는 현재 열을 의미

	if (cur == n) {
		cnt++;
		return;
	}

	for (int i = 0; i < n; i++) {
		if (isUsed1[i] == 0 && isUsed2[i + cur] == 0 && isUsed3[i - cur + n - 1] == 0) {
			// isUsed1 : 놓으려는 위치와 같은 열이 비어있는가?
			// isUsed2 : 놓으려는 위치와 좌하단-우상단을 잇는 대각선과 평행한 대각선이 비어있는가?
			// isUsed3 : 놓으려는 위치와 좌상단-우하단을 잇는 대각선과 평행한 대각선이 비어있는가?
			// -n < i - cur < n   ->   0 <= i - cur + n - 1 < 2n - 1
			// i - cur은 배열 밖을 참조할 수 있으므로, n - 1을 더하여 항상 유효한 원소만을 참조할 수 있게 함.


			// 퀸을 놓음으로 인해서 놓지 못하게 되는 곳의 isUsed값을 true로 변경.
			isUsed1[i] = 1;
			isUsed2[i + cur] = 1;
			isUsed3[i - cur + n - 1] = 1;

			
			func(cur + 1);

			// 다시 놓을 수 있도록 isUsed값을 false로 변경.
			isUsed1[i] = 0;
			isUsed2[i + cur] = 0;
			isUsed3[i - cur + n - 1] = 0;
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	func(0);

	cout << cnt << "\n";
}