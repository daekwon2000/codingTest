#include<iostream>
#include<queue>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	int arr[100001];
	int vis[100001];

	for (int i = 0; i < 100001; i++) {
		arr[i] = 0;
		vis[i] = -1;
	}

	queue<int> q;

	vis[n] = 0;
	q.push(n);

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		// cur이 범위 밖을 나가지 않도록 short cut evaluation

		// 2배 이동은 동일 시간에 방문 가능
		// 해당 위치가 아직 방문되지 않았거나 원래 비용보다 적게 든다면
		if (cur * 2 >= 0 && cur * 2 < 100001 && (vis[cur * 2] == -1 || vis[cur * 2] > vis[cur])) {
			vis[cur * 2] = vis[cur];
			q.push(cur * 2);
		}
		
		// -1 이동
		if (cur - 1 >= 0 && cur - 1 < 100001 && (vis[cur - 1] == -1 || vis[cur - 1] > vis[cur] + 1)) {
			vis[cur - 1] = vis[cur] + 1;
			q.push(cur - 1);
		}

		// +1 이동
		if (cur + 1 >= 0 && cur + 1 < 100001 && (vis[cur + 1] == -1 || vis[cur + 1] > vis[cur] + 1)) {
			vis[cur + 1] = vis[cur] + 1;
			q.push(cur + 1);
		}
	}

	cout << vis[m] << "\n";
}