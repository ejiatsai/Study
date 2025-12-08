#include <stdio.h>

int num(int x);

int main(void){
    int a;
    scanf("%d", &a);
    if(num(a) == 1){
        printf("Even\n");
    }
    else {
        printf("Odd\n");
    }
}

int num(int x){
    if(x % 2 == 0){
        return 1;
    }
    else {
        return 0;
    }
}