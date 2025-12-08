#include <stdio.h>

void swap(int *a,int *b);

int main(){
    int a,b;

    scanf("%d%d",&a,&b);

    printf("Before: %d, %d\n",a,b);

    swap(&a,&b);

    printf("After: %d, %d\n",a,b);
}

void swap(int *a,int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}