#include<iostream>
#include<algorithm>

using namespace std;

int n, m;
int arr[10];
int isUsed[10];

void func(int k) {
	if (k == m) {
		for (int i = 0; i < m; i++) {
			cout << arr[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = 0; i < n; i++) {
		// 1부터 n까지 각 원소를 시작점으로 삼는다. (0-based)

		if (isUsed[i] == 0) {
			// 해당 위치를 사용했었다면 skip

			// 출력 배열에 삽입
			arr[k] = i + 1;
			// 해당 위치의 원소를 사용했음을 알린다.
			isUsed[i] = 1;
			// 다음 칸에 넣기 위한 재귀함수 호출
			func(k + 1);
			// 재귀함수가 끝난 후, 나 자신의 사용 기록을 비운다
			isUsed[i] = 0;
		}
	}
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;

	func(0);	
}