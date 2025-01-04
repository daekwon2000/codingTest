#include <string>
#include <vector>

using namespace std;

void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int solution(vector<int> wallet, vector<int> bill) {
    
    int answer = 0;
    
    // 지갑 길이에 대한 정보는 변수명을 따로 지정
    int wallet_long = wallet[0];
    int wallet_short = wallet[1];
    // wallet_long에 긴 길이가 들어가도록 회전
    if(wallet[1] >= wallet[0]){
        wallet_long = wallet[1];
        wallet_short = wallet[0];
    }
    
    while(true){
        // bill[0]에 항상 긴 길이가 들어가도록
        if(bill[1] >= bill[0]){
            swap(&bill[0], &bill[1]);
        }
        
        // 만약 조건을 충족하면 break
        if(wallet_long >= bill[0] && wallet_short >= bill[1]){
            break;
        }
        
        // 만약 조건을 충족하지 않는다면
        // 접는 과정 수행
        
        // answer 1 증가
        answer++;
    
        // 긴 쪽의 지폐를 반으로 접음
        bill[0] = bill[0] / 2;
        
    }
    
    return answer;
}