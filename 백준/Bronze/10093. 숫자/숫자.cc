#include<iostream>

using namespace std;

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	long long a;
	long long b;

	cin >> a >> b;

	if (b < a) {
		long long temp = b;
		b = a;
		a = temp;
	}

	if (a == b || a + 1 == b) {
		cout << 0 << "\n";
		return 0;
	}

	cout << b - a - 1 << "\n";

	for (long long i = 1; i <= b - a - 1; i++) {
		cout << a + i << " ";
	}
}