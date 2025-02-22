#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main(){
    vector<int> vec;
    
    int n = 0;
    cin >> n;
    
    for(int i = 0; i < n; i++){
        int tmp;
        cin >> tmp;
        vec.push_back(tmp);
    }
    
    sort(vec.begin(), vec.end());
    
    for(int i = 0; i < vec.size(); i++){
        cout << vec[i] << "\n";
    }
}