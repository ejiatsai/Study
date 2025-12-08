#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main(void){
    double num = 0;
    int size = 0;
    int sum = 0;
    srand(time(NULL));
    scanf("%d", &size);
    for(int i = 0; i < size; i++){
        double x = (double) rand() / (RAND_MAX + 1.0);
        double y = (double) rand() / (RAND_MAX + 1.0);
        double dist = sqrt(x * x + y * y);
        if(dist <= 1){
            sum ++;
        }
    }
    num = ((double)sum / (size)) * 4;
    printf("%f\n", num);
    return 0;
}
