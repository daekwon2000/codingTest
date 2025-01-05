#include <string>
#include <vector>

using namespace std;

void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int solution(vector<vector<int>> sizes) {
    int answer = 0;
    
    int width = 0;
    int height = 0;
    
    int cnt = sizes.size();
    
    for(int i = 0; i < cnt; i++){
        // [0]에 긴 길이를, [1]에 짧은 길이를 넣도록 반복
        // 만약 [1]에 더 긴 길이가 들어가 있다면, swap 함수 호출
        if(sizes[i][1] > sizes[i][0]){
            swap(sizes[i][0], sizes[i][1]);
        }
        
        // 만약 해당 명함의 가로 길이가 원래 최대 가로 길이보다 길다면 변경
        if(width < sizes[i][0]){
            width = sizes[i][0];
        }
        
        // 만약 해당 명함의 세로 길이가 원래 최대 세로 길이보다 길다면 변경
        if(height < sizes[i][1]){
            height = sizes[i][1];
        }
    }
    
    answer = width * height;
    
    return answer;
}