#include <stdio.h>
#include <stdlib.h>

int cmp(const void* a,const void* b);

int main(void){
    int n = 0,q = 0;
    scanf("%d",&n);
    int T[n];
    for(int i = 0; i < n; i++){
        scanf("%d",&T[i]);
    }
    scanf("%d",&q);
    int S[q];
    for(int i = 0;i < q;i++){
        scanf("%d",&S[i]);
    }
    qsort(T,n,sizeof(int),cmp);
    qsort(S,q,sizeof(int),cmp);
    int t1 = 0,t2 = 0;
    if(n > q){
        t1 = n;
        t2 = q;
    }
    else{
        t1 = q;
        t2 = n;
    }
    int count = 0;
    if(n == t1){
        for(int i = 0;i < t1;i++){
            if(T[i] == T[i-1]){
                continue;
            }
            for(int j = 0;j < t2;j++){
                if(T[i] == S[j]){
                    count++;
                    break;
                }
            }
        }
    }
    else if(n == t2){
        for(int i = 0;i < t2;i++){
            if(S[i] == S[i-1]){
                continue;
            }
            for(int j = 0;j < t1;j++){
                if(S[i] == T[j]){
                    count++;
                    break;
                }
            }
        }
    }
    printf("%d",count);
}

int cmp(const void* a,const void* b){
    int va = *(int*)a;
    int vb = *(int*)b;
    if(va > vb) return 1;
    else return 0;
}