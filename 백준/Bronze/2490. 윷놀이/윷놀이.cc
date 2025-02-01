#include<iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	for (int round = 0; round < 3; round++) {

		int yeet = 0;
		int bae = 0;
		int deung = 0;

		for (int i = 0; i < 4; i++) {
			
			cin >> yeet;

			if (yeet == 0) {
				bae++;
			}
			else {
				deung++;
			}
		}

		if (bae == 1) {
			cout << "A\n";
		}
		else if (bae == 2) {
			cout << "B\n";
		}
		else if (bae == 3) {
			cout << "C\n";
		}
		else if (bae == 4) {
			cout << "D\n";
		}
		else {
			cout << "E\n";
		}
	}

}