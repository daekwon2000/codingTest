#include<iostream>

using namespace std;

long long func(long long a, long long b, long long c) {
	long long mod = 0;
	if (b == 1) {
		return a % c;
	}

	if (b % 2 == 1) {
		return mod = (func(a, b / 2, c) * func(a, b / 2 + 1, c)) % c;
	}
	else {
		return mod = (func(a, b / 2, c) * func(a, b / 2, c)) % c;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	long long a, b, c;
	cin >> a >> b >> c;

	long long mod = func(a, b, c);

	cout << mod << "\n";
}