#include<iostream>
#include<cstdlib>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string s;
	string t;

	cin >> s >> t;

	int arr_s[26] = {};
	int arr_t[26] = {};

	for (int i = 0; i < s.length(); i++) {
		arr_s[s[i] - 'a']++;
	}
	for (int i = 0; i < t.length(); i++) {
		arr_t[t[i] - 'a']++;
	}

	int ans = 0;

	for (int i = 0; i < 26; i++) {
		ans += abs(arr_s[i] - arr_t[i]);
	}

	cout << ans << "\n";
}