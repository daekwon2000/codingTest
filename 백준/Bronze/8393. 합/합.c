#include<stdio.h>
int main(){
    int n;
    int hap = 0;
    scanf("%d", &n);
    for(int i = 1; i < n + 1; i++){
        hap = hap + i;
    }
    printf("%d", hap);
}