#include <stdio.h>
#define SIZE 100

int main(void){
    int r = 0,c = 0;
    scanf("%d",&r);
    scanf("%d",&c);
    int table[SIZE][SIZE] = {0};
    for(int i = 0;i < r;i++){
        for(int j = 0;j < c;j++){
            scanf("%d",&table[i][j]);
        }
    }
    for(int i = 0;i < r;i++){
        int sumR = 0;
        for(int j = 0;j < c;j++){
            sumR += table[i][j];
        }
        table[i][c] = sumR;
    }
    for(int i = 0;i < c + 1;i++){
        int sumC = 0;
        for(int j = 0;j < r;j++){
            sumC += table[j][i];
        }
        table[r][i] = sumC;
    }
    int sum = 0;
    for(int i = 0;i < c;i++){
        sum += table[r][i];
    }
    table[r][c] = sum;
    for(int i = 0;i < r + 1;i++){
        printf("%d",table[i][0]);
        for(int j = 1;j < c + 1;j++){
            printf(" %d",table[i][j]);
        }
        printf("\n");
    }
}