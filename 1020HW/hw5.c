#include <stdio.h>
#include <math.h>

int main(){
    int n;
    scanf("%d", &n);
    double dis = 0;
    int x[n], y[n],fx[10] = {0}, fy[10] = {0};
    for(int i = 0;i < n;i++){
        scanf("%d %d", &x[i], &y[i]);
        fx[0] += x[i];
        fy[0] += y[i];
        dis += sqrt((double)(pow(x[i], 2) + pow(y[i], 2)));
    }
    printf("%d %d %.2f", fx[0], fy[0], dis);
}