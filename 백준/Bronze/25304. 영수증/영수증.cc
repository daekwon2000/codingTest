#include<iostream>

using namespace std;

int main(){
    int x, n;
    
    cin >> x >> n;
    
    int sum = 0;
    
    for(int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        sum += a * b;
    }
    
    if(sum == x){
        cout << "Yes\n";
    }else{
        cout << "No\n";
    }
}