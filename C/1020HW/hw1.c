#include <stdio.h>

int main(void){
    int n = 0;
    scanf("%d",&n);
    int temp1 = n;
    int arr[n];
    for(int i = 0; i < n;i++){
        scanf("%d",&arr[i]);
    }
    for(int i = 0;i < n/2;i++){
        int temp2 = arr[i];
        arr[i] = arr[temp1-1];
        arr[temp1-1] = temp2;
        temp1--;
    }
    printf("%d",arr[0]);
    for(int i = 1;i < n;i++){
        printf(" %d",arr[i]);
    }
}