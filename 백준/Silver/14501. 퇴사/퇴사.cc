#include <iostream>
#include <algorithm>

using namespace std;

int n;
int term[16], price[16], d[16];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> term[i] >> price[i];
    }

    // DP 테이블 갱신
    for (int i = n; i >= 1; i--) {
        if (i + term[i] > n + 1) {  // 상담이 퇴사일을 넘으면
            d[i] = d[i + 1];  // 그날 상담을 하지 않음
        } else {
            d[i] = max(d[i + term[i]] + price[i], d[i + 1]);
        }
    }

    cout << d[1] << "\n";  // 첫째 날부터 시작할 때의 최대 이익 출력
}
