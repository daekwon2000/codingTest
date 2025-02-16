#include <iostream>
#include <algorithm>

using namespace std;

int arr[1000002]; // 최소 연산 횟수 저장
int rev[1000002]; // 경로 추적

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    arr[1] = 0; // 1에서 1로 가는 경우 연산 필요 없음
    rev[1] = 0; // 경로 저장을 위한 초기값

    for (int i = 2; i <= n; i++) {
        arr[i] = arr[i - 1] + 1; // 기본적으로 -1 연산 사용
        rev[i] = i - 1; // 기본 경로는 -1 연산

        if (i % 2 == 0 && arr[i] > arr[i / 2] + 1) {
            arr[i] = arr[i / 2] + 1;
            rev[i] = i / 2; // 2로 나눈 경우 경로 저장
        }
        if (i % 3 == 0 && arr[i] > arr[i / 3] + 1) {
            arr[i] = arr[i / 3] + 1;
            rev[i] = i / 3; // 3으로 나눈 경우 경로 저장
        }
    }

    cout << arr[n] << "\n"; // 최소 연산 횟수 출력

    // 경로 출력
    while (n > 0) {
        cout << n << " ";
        n = rev[n];
    }
    cout << "\n";

    return 0;
}
