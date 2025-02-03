#include<iostream>
#include<list>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string s;
	cin >> s;

	int m = 0;
	cin >> m;

	list<char> lst;

	for (int i = 0; i < s.length(); i++) {
		lst.push_back(s[i]);
	}

	auto iter = lst.end();

	for (int i = 0; i < m; i++) {
		char op;
		cin >> op;

		if (op == 'P') {
			char a;
			cin >> a;

			lst.insert(iter, a);
		}
		else {
			if (op == 'L') {
				if (iter == lst.begin()) {
					continue;
				}

				iter--;
			}
			else if (op == 'D') {
				if (iter == lst.end()) {
					continue;
				}

				iter++;
			}
			else if (op == 'B') {
				if (iter == lst.begin()) {
					continue;
				}

				iter--;

				iter = lst.erase(iter);
			}
		}
	}

	for (auto t : lst) {
		cout << t;
	}

	cout << "\n";
}