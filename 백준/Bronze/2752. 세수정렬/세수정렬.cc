#include<iostream>
#include<vector>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	vector<int> arr(3);
	cin >> arr[0] >> arr[1] >> arr[2];

	for (int i = 0; i < 2; i++) {
		for (int j = i + 1; j < 3; j++) {
			if (arr[i] > arr[j]) {
				int temp = arr[j];
				arr[j] = arr[i];
				arr[i] = temp;
			}
		}
	}

	cout << arr[0] << " " << arr[1] << " " << arr[2];

}