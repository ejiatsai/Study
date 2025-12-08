#include <stdio.h>

int main(void){
    int S = 0;
    scanf("%d",&S);
    int h = 0,m = 0,s = 0;
    s = S % 60;
    S -= s;
    m = (S % 3600) / 60;
    S -= m;
    h = S / 3600;
    printf("%d:%d:%d",h,m,s);
}