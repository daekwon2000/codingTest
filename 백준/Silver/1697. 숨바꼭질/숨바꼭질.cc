#include<iostream>
#include<queue>

using namespace std;

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int arr[100001] = {};
	int vis[100001] = {};

	for (int i = 0; i < 100001; i++) {
		vis[i] = -1;
	}
	
	int dx[2] = {};
	queue<int> q;

	int n, m;
	cin >> n >> m;

	arr[n] = 1;
	arr[m] = -1;

	vis[n] = 0;
	q.push(n);

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		int x[3] = { cur - 1, cur + 1, cur * 2 };

		for (int i = 0; i < 3; i++) {
			if (x[i] < 0 || x[i] > 100000) { // 굳이 범위 밖에 나갈 필요가 없음.
				continue;
			}
			if (vis[x[i]] >= 0) { // 이미 방문 하였음.
				continue;
			}
			//if (arr[x[i]] == -1) { // 찾으면 최대한 빠르게 return;
			//	cout << vis[cur] + 1 << "\n";

			//	return 0;
			//}

			vis[x[i]] = vis[cur] + 1;
			q.push(x[i]);
		}

	}

	cout << vis[m] << "\n";
}