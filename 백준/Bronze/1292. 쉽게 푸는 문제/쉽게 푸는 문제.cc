#include<iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int arr[1002] = {};

    int a, b;
    cin >> a >> b;

    int sum = 0;

    int cnt = 1;
    for (int i = 1; i <= 1000;) {
        for (int j = 0; j < cnt; j++) {
            if (i > 1000) {
                break;
            }
            arr[i] = cnt;
            i++;
        }
        cnt++;
    }

 /*   for (int i = 0; i < 100; i++) {
        cout << arr[i] << " ";
    }*/

    for (int i = a; i <= b; i++) {
        sum += arr[i];
    }

    cout << sum << "\n";
}