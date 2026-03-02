#include <stdio.h>

int main() {
    unsigned int a, b;
    while(scanf("%u%u", &a, &b)!=EOF){
        unsigned int sum = 0,count = 1;
        sum = a + b;
        for(int i = 10;i <= sum;i *= 10){
            count ++;
        }
        printf("%u\n",count);
    }

    return 0;
}
