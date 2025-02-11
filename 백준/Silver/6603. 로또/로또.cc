#include<iostream>
#include<algorithm>

using namespace std;

int k;

int arr[13];
int output[13];
int isUsed[13];

void func(int depth, int prev) {
	if (depth == 6) {
		for (int i = 0; i < depth; i++) {
			cout << output[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = 0; i < k; i++) {
		if (isUsed[i] == 0) {
			if (arr[i] < prev) {
				continue;
			}
			isUsed[i] = 1;
			output[depth] = arr[i];
			func(depth + 1, arr[i]);
			isUsed[i] = 0;
		}
	}
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	while (true) {
		cin >> k;
		
		if (k == 0) {
			break;
		}

		for (int i = 0; i < k; i++) {
			cin >> arr[i];
		}

		sort(arr, arr + k);
		
		func(0, 0);

		cout << "\n";
	}
}