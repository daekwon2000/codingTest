#include<iostream>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n = 0;
    cin >> n;
    
    long long arr[102] = {};
    
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    
    long long sz = 0;
    cin >> sz;
    
    long long cnt = 0;
    for(int i = 0; i < n; i++){
        long long tmp = 0;
        
        if(arr[i] % sz == 0){
            tmp = arr[i] / sz;
            cnt += tmp;
        }else{
            tmp = (arr[i] / sz) + 1;
            cnt += tmp;
        }
        
    }
    
    cout << sz * cnt << "\n";
}