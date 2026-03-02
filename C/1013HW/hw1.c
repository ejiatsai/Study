#include <stdio.h>

int min(int a,int b,int c);
int main(void) {
    int n1,n2,n3;
    scanf("%d %d %d", &n1, &n2, &n3);
    printf("min = %d\n", min(n1,n2,n3));
    return 0;
}

int min(int a,int b,int c){
    int tem = a;
    tem = (b < tem) ? b : tem;
    tem = (c < tem) ? c : tem;
    return tem;
}