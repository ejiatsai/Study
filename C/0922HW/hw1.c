#include <stdio.h>
#include <stdlib.h>

int cmp(const void* a,const void* b);

int main(void){
    int n = 0;
    scanf("%d",&n);
    int num[n];
    int sum = 0;
    for(int i = 0;i < n;i++){
        scanf("%d",&num[i]);
        sum += num[i];
    }
    qsort(num,n,sizeof(int),cmp);
    printf("%d %d %d",num[0],num[n-1],sum);
}

int cmp(const void* a,const void* b){
    int va = *(int*)a;
    int vb = *(int*)b;
    if(va > vb) return 1;
    else return 0;
}