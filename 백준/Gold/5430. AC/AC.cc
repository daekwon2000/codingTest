#include<iostream>
#include<deque>

using namespace std;

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int t = 0;
	cin >> t;

	for (int i = 0; i < t; i++) {

		deque<int> d;
		int check_error = 1;
		char direction = 'L';
		
		string comm;
		cin >> comm;

		int n = 0;
		cin >> n;

		string arr;
		cin >> arr;

		arr.pop_back();
		arr.push_back(',');

		/*for (int j = 0; j < n; j++) {
			d.push_back(arr[2 * j + 1] - '0');
		}*/

		int idx = 1;
		for (int j = 0; j < n; j++) {
			int val = 0;
			
			while (arr[idx] != ',') {
				val *= 10;
				val += arr[idx] - '0';
				idx++;
			}

			idx++;

			d.push_back(val);
		}

		for (int j = 0; j < comm.length(); j++) {
			if (comm[j] == 'R') {
				if (direction == 'L') {
					direction = 'R';
				}
				else {
					direction = 'L';
				}
			}
			else if (comm[j] == 'D') {
				if (d.size() == 0) {
					check_error = 0;
					break;
				}
				else {
					if (direction == 'L') {
						d.pop_front();
					}
					else {
						d.pop_back();
					}
				}
			}
		}

		if (check_error == 0) {
			cout << "error\n";
		}
		else {
			cout << "[";
			if (direction == 'L') {
				int sz = d.size();
				for (int j = 0; j < sz - 1; j++) {
					cout << d[j] << ",";
				}
				if (sz - 1 >= 0) {
					cout << d[sz - 1];
				}
			}
			else {
				int sz = d.size();
				for (int j = sz - 1; j > 0; j--) {
					cout << d[j] << ",";
				}
				if (sz - 1 >= 0) {
					cout << d[0];
				}
			}
			cout << "]\n";
		}
	}
}