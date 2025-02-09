#include<iostream>
#include<array>
using namespace std;

int main() {
	int x, y, w, h;

	for (int i = 1; i < 2; ++i) {
		cin >> x >> y >> w >> h;
		if (w <= 1000 && h <= 1000 && 1 < x < w - 1 && 1 < y < h - 1) {

		}
		else {
			i--;
		}
	}

	int shortest = x;
	if (w - x < shortest) {
		shortest = w - x;
	}
	if (y < shortest) {
		shortest = y;
	}
	if (h - y < shortest) {
		shortest = h - y;
	}

	cout << shortest;
}