#include <stdio.h>

int gcd(int a,int b);

int main(void){
    long long a,b;
    while(scanf("%lld%lld",&a,&b) != EOF){
        long long tmp;
        tmp = a * b;
        printf("%d %lld\n",gcd(a,b),tmp / gcd(a,b));
    }
}

int gcd(int x,int y){
    if(y > x){
        int tmp = x;
        x = y;
        y = tmp;
    }
    while(y != 0){
        int r = x % y;
        x = y;
        y = r;
    }
    return x;
}