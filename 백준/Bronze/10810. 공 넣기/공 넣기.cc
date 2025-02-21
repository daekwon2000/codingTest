#include<iostream>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    
    int arr[101] = {};
    
    for(int i = 0; i < m; i++){
        int x, y, z;
        cin >> x >> y >> z;
        for(int j = x; j <= y; j++){
            arr[j] = z;
        }
    }
    
    for(int i = 1; i <= n; i++){
        cout << arr[i] << " ";
    }
    cout << "\n";
}