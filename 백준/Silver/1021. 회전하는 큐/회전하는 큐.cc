#include<iostream>
#include<deque>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n = 0;
	cin >> n;

	int m = 0;
	cin >> m;

	deque<int> d;
	int cnt = 0;

	for (int i = 1; i <= n; i++) {
		d.push_back(i);
	}

	for (int i = 0; i < m; i++) {
		int x = 0;
		cin >> x;

		int idx = 0;

		for (int j = 0; j < n - i; j++) {
			if (d[j] == x) {
				idx = j;
				break;
			}
		}

		if (idx <= (n - i - 1) / 2) {
			for (int j = 0; j < idx; j++) {
				int tmp = 0;
				tmp = d.front();
				d.pop_front();
				d.push_back(tmp);
				cnt++;
			}
		}
		else {
			for (int j = 0; j < n - i - idx; j++) {
				int tmp = 0;
				tmp = d.back();
				d.pop_back();
				d.push_front(tmp);
				cnt++;
			}
		}

		d.pop_front();
	}

	cout << cnt << "\n";
}