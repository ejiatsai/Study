#include <stdio.h>

int main(void){
    int n = 0,x = 0;
    while(1){
        scanf("%d",&n);
        scanf("%d",&x);
        if(n == 0 && x == 0){
            break;
        }
        int count = 0;
        for(int i = 1;i <= n - 2;i++){
            for(int j = i+1;j < n;j++){
                int k = x - i - j;
                if(k <= n && i < j && j < k && k >= 1){
                    count++;
                }
            }
        }
        printf("%d\n",count);
    }
}