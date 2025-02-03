#include<iostream>
#include<list>

using namespace std;

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	list<int> lst_origin;
	list<int> lst_output;

	int n, k;
	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		lst_origin.push_back(i + 1);
	}

	auto iter = lst_origin.begin();

	for (int i = 0; i < n; i++) {

		for (int j = 0; j < k - 1; j++) {
			if (iter == lst_origin.end()) {
				iter = lst_origin.begin();
			}
			iter++;
			if (iter == lst_origin.end()) {
				iter = lst_origin.begin();
			}
		}

		lst_output.push_back(*iter);

		iter = lst_origin.erase(iter);

		/*for (auto t : lst_output) {
			cout << t << ", ";
		}*/
	}

	iter = lst_output.begin();
	
	cout << "<";
	for (int i = 0; i < lst_output.size(); i++) {
		if (i != lst_output.size() - 1) {
			cout << *iter << ", ";
		}
		else {
			cout << *iter;
		}
		iter++;
	}
	cout << ">";
}