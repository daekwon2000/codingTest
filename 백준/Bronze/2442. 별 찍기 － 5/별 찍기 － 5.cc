#include<iostream>

using namespace std;

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int n = 0;
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			cout << " ";
		}
		for (int j = 0; j < 2 * i + 1; j++) {
			cout << "*";
		}
		cout << "\n";
	}
}