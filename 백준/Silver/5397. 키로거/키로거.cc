#include<iostream>
#include<list>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n = 0;
	cin >> n;

	for (int i = 0; i < n; i++) {
		
		string s;
		cin >> s;

		list<char> lst;

		auto iter = lst.end();
		
		for (int j = 0; j < s.length(); j++) {

			if (s[j] == '<') {
				if (iter == lst.begin()) {
					continue;
				}

				iter--;
			}
			else if (s[j] == '>') {
				if (iter == lst.end()) {
					continue;
				}

				iter++;
			}
			else if (s[j] == '-') {
				if (iter == lst.begin()) {
					continue;
				}

				iter--;
				iter = lst.erase(iter);
			}
			else {
				lst.insert(iter, s[j]);
			}

		}

		for (auto t : lst) {
			cout << t;
		}
		cout << "\n";
	}
}