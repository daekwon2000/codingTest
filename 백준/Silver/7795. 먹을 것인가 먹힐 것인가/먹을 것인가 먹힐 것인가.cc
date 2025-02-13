#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t = 0;
	cin >> t;

	while (t--) {
		int n, m;
		cin >> n >> m;

		vector<int> a;
		vector<int> b;

		for (int i = 0; i < n; i++) {
			int tmp;
			cin >> tmp;

			a.push_back(tmp);
		}

		for (int i = 0; i < m; i++) {
			int tmp;
			cin >> tmp;

			b.push_back(tmp);
		}

		sort(a.begin(), a.end());
		sort(b.begin(), b.end());

		//a.erase(unique(a.begin(), a.end()), a.end());
		//b.erase(unique(b.begin(), b.end()), b.end());

		int ans = 0;
		int idx = 0;
		int tmp = 0;

		for (int i = 0; i < a.size(); i++) {
			ans += idx;
			while (true) {
				if (idx >= b.size()) {
					break;
				}
				if (a[i] > b[idx]) {
					ans++;
					idx++;
				}
				else {
					break;
				}
			}
		}

		cout << ans << "\n";
	}
}