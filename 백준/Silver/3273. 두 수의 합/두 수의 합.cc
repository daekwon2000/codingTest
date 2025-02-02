#include<iostream>
#include<vector>

using namespace std;

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	vector<int> arr;

	int n = 0;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		arr.push_back(temp);
	}

	int x = 0;
	cin >> x;

	int arr_2[2000001] = { };

	for (int i = 0; i < n; i++) {
		arr_2[arr[i]]++;
	}

	int cnt = 0;

	for (int i = 0; i < n; i++) {
		if (arr[i] >= x) {
			continue;
		}
		if (arr_2[x - arr[i]] != 0) {
			cnt++;
		}
	}

	cout << cnt / 2 << "\n";

}