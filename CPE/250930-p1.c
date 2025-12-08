#include <stdio.h>

int three_n_plus_one(int x,int y);

int main(void){
    int i,j;
    while(scanf("%d %d",&i,&j) != EOF){
        printf("%d %d %d\n",i,j,three_n_plus_one(i,j));
    }
}

int three_n_plus_one(int x,int y){
    int max = 1;
    if(x > y){
        int temp = x;
        x = y;
        y = temp;
    }
    for(int i = x;i <= y;i++){
        int count = 1;
        int n = i;
        while(n != 1){
            if(n % 2 != 0){
                n = 3*n + 1;
                count++;
            }
            else {
                n /= 2;
                count++;
            }
        }
        if(count > max){
            max = count;
        }
    }
    return max;
}