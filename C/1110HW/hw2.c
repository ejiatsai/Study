#include <stdio.h>

int main(void){
    int A[120][120],B[120][120],C[120][120];
    int n,m,l;
    scanf("%d%d%d",&n,&m,&l);
    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            scanf("%d",&A[i][j]);
        }
    }
    for(int i = 0;i < m;i++){
        for(int j = 0;j < l;j++){
            scanf("%d",&B[i][j]);
        }
    }
    for(int i = 0;i < n;i++){
        for(int j = 0;j < l;j++){
            for(int k = 0;k < m;k++){
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    for(int i = 0;i < n;i++){
        printf("%d",C[i][0]);
        for(int j = 1;j < l;j++){
            printf(" %d",C[i][j]);
        }
        printf("\n");
    }
}