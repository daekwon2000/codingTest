#include<iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n = 0;
	cin >> n;

	const int MX = 10000;
	int arr[2 * MX + 1] = {};
	int size = 0;
	int front = MX;
	int back = MX;

	for (int i = 0; i < n; i++) {

		string s;
		cin >> s;

		if (s == "push_front") {
			int a = 0;
			cin >> a;

			size++;
			front--;
			arr[front] = a;
		}
		else if (s == "push_back") {
			int a = 0;
			cin >> a;

			size++;
			arr[back] = a;
			back++;
		}
		else if (s == "pop_front") {
			if (size != 0) {
				cout << arr[front] << "\n";
				size--;
				front++;
			}
			else {
				cout << -1 << "\n";
			}
		}
		else if (s == "pop_back") {
			if (size != 0) {
				cout << arr[back - 1] << "\n";
				size--;
				back--;
			}
			else {
				cout << -1 << "\n";
			}
		}
		else if (s == "size") {
			cout << size << "\n";
		}
		else if (s == "empty") {
			if (size != 0) {
				cout << 0 << "\n";
			}
			else {
				cout << 1 << "\n";
			}
		}
		else if (s == "front") {
			if (size != 0) {
				cout << arr[front] << "\n";
			}
			else {
				cout << -1 << "\n";
			}
		}
		else if (s == "back") {
			if (size != 0) {
				cout << arr[back - 1] << "\n";
			}
			else {
				cout << -1 << "\n";
			}
		}

	}
}