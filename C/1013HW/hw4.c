#include <stdio.h>

int factor(int x,int y);

int main(void){
    int a,b;
    scanf("%d %d", &a, &b);
    if(factor(a,b) == 1){
        puts("Yes");
    }
    else {
        puts("No");
    }
    return 0;
}

int factor(int x,int y){
    if(x % y == 0){
        return 1;
    }
    else {
        return 0;
    }
}
