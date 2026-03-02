#include <stdio.h>
#include <math.h>

int main(void){
    while (1){
        int n = 0;
        scanf("%d",&n);
        if(n == 0){
            break;
        }
        int arr[n];
        for(int i = 0; i < n;i++){
            scanf("%d",&arr[i]);
        }
        int sum = 0;
        for(int i = 0;i < n;i++){
            sum += arr[i];
        }
        double avg = (double)sum / n;
        double SD = 0;
        for(int i = 0;i < n;i++){
            SD += (double)((double)arr[i] - avg) * ((double)arr[i] - avg) / n;
        }
        SD = sqrt(SD);
        printf("%.3f\n",SD);
    }    
}