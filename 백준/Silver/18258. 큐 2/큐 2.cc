#include<iostream>
#include<queue>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n = 0;
	cin >> n;

	int arr[2000001] = {};
	int front = 0;
	int rear = 0;
	int size = 0;

	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;

		if (s == "push") {
			int a = 0;
			cin >> a;

			arr[rear] = a;
			rear++;
			size++;
		}
		else if (s == "pop") {
			if (front == rear) {
				cout << -1 << "\n";
			}
			else {
				cout << arr[front] << "\n";
				front++;
				size--;
			}
		}
		else if (s == "front") {
			if (front == rear) {
				cout << -1 << "\n";
			}
			else {
				cout << arr[front] << "\n";
			}
		}
		else if (s == "back") {
			if (front == rear) {
				cout << -1 << "\n";
			}
			else {
				cout << arr[rear - 1] << "\n";
			}
		}
		else if (s == "size") {
			cout << size << "\n";
		}
		else if (s == "empty") {
			if (size == 0) {
				cout << 1 << "\n";
			}
			else {
				cout << 0 << "\n";
			}
		}
	}
}
