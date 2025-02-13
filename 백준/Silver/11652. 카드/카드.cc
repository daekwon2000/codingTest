#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

bool cmp(pair<int, long long>& a, pair<int, long long>& b) {
	if (a.first > b.first) {
		return true;
	}
	else if (a.first == b.first) {
		if (a < b) {
			return true;
		}
		else {
			return false;
		}
	}
	else {
		return false;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n = 0;
	cin >> n;

	long long arr[100002];

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	sort(arr, arr + n);
	
	vector<pair<int, long long>> output;

	int cnt = 0;

	long long tmp = arr[0];
	for (int i = 0; i < n; i++) {
		if (arr[i] == tmp) {
			cnt++;
		}
		else {
			output.push_back({ cnt, tmp });
			tmp = arr[i];
			cnt = 1;
		}
	}

	output.push_back({ cnt, tmp });

	int mx = -1;
	int idx = 0;
	for (int i = 0; i < output.size(); i++) {
		if (output[i].first > mx) {
			idx = i;
			mx = output[i].first;
		}
	}

	cout << output[idx].second << "\n";

	//// 숫자의 개수, 숫자의 종류
	//pair<int, long long> arr[100002];

	//int n = 0;
	//cin >> n;

	//for (int i = 0; i < n; i++) {
	//	long long tmp = 0;
	//	cin >> tmp;

	//	int check = 1;

	//	for (int j = 0; j < i; j++) {
	//		if (arr[j].second == tmp) {
	//			check = 0;
	//			arr[j].first++;
	//			break;
	//		}
	//	}

	//	if (check == 1) {
	//		arr[i].first++;
	//		arr[i].second = tmp;
	//	}
	//}

	//sort(arr, arr + n, cmp);

	////for (int i = 0; i < n; i++) {
	////	cout << arr[i].first << " " << arr[i].second << "\n";
	////}

	//cout << arr[0].second << "\n";
}