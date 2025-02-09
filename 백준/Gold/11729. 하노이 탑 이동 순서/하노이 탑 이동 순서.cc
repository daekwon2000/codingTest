#include<iostream>
#include<cmath>

using namespace std;

//int cnt = 0;
//
//void hanoi(int n, int start,int dest) {
//	if (n == 1) {
//		cout << start << " " << dest << "\n";
//		cnt++;
//		return;
//	}
//	cnt++;
//	if (start == 1) {
//		if (dest == 2) {
//			hanoi(n - 1, 1, 3);
//			cout << start << " " << dest << "\n";
//			hanoi(n - 1, 3, 2);
//		}
//		else if (dest == 3) {
//			hanoi(n - 1, 1, 2);
//			cout << start << " " << dest << "\n";
//			hanoi(n - 1, 2, 3);
//		}
//	}
//	else if (start == 2) {
//		if (dest == 1) {
//			hanoi(n - 1, 2, 3);
//			cout << start << " " << dest << "\n";
//			hanoi(n - 1, 3, 1);
//		}
//		else if (dest == 3) {
//			hanoi(n - 1, 2, 1);
//			cout << start << " " << dest << "\n";
//			hanoi(n - 1, 1, 3);
//		}
//	}
//	else if (start == 3) {
//		if (dest == 1) {
//			hanoi(n - 1, 3, 2);
//			cout << start << " " << dest << "\n";
//			hanoi(n - 1, 2, 1);
//		}
//		else if (dest == 2) {
//			hanoi(n - 1, 3, 1);
//			cout << start << " " << dest << "\n";
//			hanoi(n - 1, 1, 2);
//		}
//	}
//}

void hanoi2(int n, int start, int dest) {
	if (n == 1) {
		cout << start << " " << dest << "\n";
		return;
	}
	hanoi2(n - 1, start, 6 - start - dest);
	cout << start << " " << dest << "\n";
	hanoi2(n - 1, 6 - start - dest, dest);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n = 0;
	cin >> n;

	cout << (1<<n) - 1 << "\n";

	hanoi2(n, 1, 3);

	//cout << cnt << "\n";
}