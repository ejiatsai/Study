#include <stdio.h>
#define SIZE 120

int main(void){
    int n = 0;
    int a[SIZE];
    scanf("%d",&n);
    for(int i = 0;i < n;i++){
        scanf("%d",&a[i]);
    }
    int count = 0;
    for (int i = 1; i < n;i++) {
        for (int j = 0; j <= (n - 1 - i); j++) {
            if (a[j] > a[j + 1]) {
                int tmp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = tmp;
                count ++;
            }
        }
    }
    printf("%d",a[0]);
    for(int i = 1;i < n;i++){
        printf(" %d",a[i]);
    }
    printf("\n");
    printf("%d",count);
}