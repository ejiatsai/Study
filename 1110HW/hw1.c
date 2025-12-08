#include <stdio.h>
#define SIZES 100020
#define SIZET 50020

int BS(int S[SIZES],int T[SIZET],int n,int q);

int main(void){
    int n = 0,q = 0;
    scanf("%d",&n);
    int s[SIZES];
    for(int i = 0; i < n; i++){
        scanf("%d",&s[i]);
    }
    scanf("%d",&q);
    int t[SIZET];
    for(int i = 0;i < q;i++){
        scanf("%d",&t[i]);
    }
    printf("%d",BS(s,t,n,q));
}

int BS(int S[SIZES],int T[SIZET],int N,int Q){
    int count = 0;
    for(int i = 0;i < Q;i++){
        int low = 0,high = N - 1,mid = 0;
        while(1){
            if(low > high) break;
            mid = (low + high) / 2;
            if(S[mid] == T[i]){
                count++;
                break;
            }
            else if(T[i] < S[mid]){
                high = mid - 1;
            }
            else low = mid + 1;
        }
    }
    return count;
}