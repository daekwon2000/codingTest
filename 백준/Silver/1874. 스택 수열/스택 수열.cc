#include<iostream>
#include<stack>
#include<vector>

using namespace std;

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int n = 0;
	cin >> n;

	stack<int> stk;
	vector<char> output;
	int pos = 1;
	int check = 1;

	for (int i = 1; i <= n; i++) {
		int k;
		cin >> k;

		if (k >= pos) {
			while (k != pos) {
				stk.push(pos);
				output.push_back('+');
				pos++;
			}

			stk.push(pos);
			output.push_back('+');
			pos++;

			stk.pop();
			output.push_back('-');
		}
		else {
			
			int tmp = stk.top();
			if (tmp == k) {
				stk.pop();
				output.push_back('-');
			}
			else {
				check = 0;
				break;
			}
		}
	}

	if (check == 0) {
		cout << "NO\n";
	}
	else {
		for (int i = 0; i < output.size(); i++) {
			cout << output[i] << "\n";
		}
	}

}
