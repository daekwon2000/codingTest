#include<iostream>
#include<typeinfo>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string s;
	cin >> s;

	//cout << typeid(s[1]).name();

	int freq[26];

	for (int i = 0; i < 26; i++) {
		freq[i] = 0;
	}

	for (int i = 0; i < s.size(); i++) {
		freq[s[i] - 'a']++;
	}

	for (int i = 0; i < 26; i++) {
		cout << freq[i] << " ";
	}
	cout << "\n";
}