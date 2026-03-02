#include <stdio.h>

unsigned int fib(unsigned int n);

int main(void){
    unsigned int num;

    while(puts("Enter n: "),scanf("%u", &num) != EOF){
        printf("Fibonacci(%u) = %u\n", num, fib(num));
    }
}

unsigned int fib(unsigned int n){
    if(n == 0){
        return 0;
    }
    else if(n == 1 || n == 2){
        return 1;
    }
    else {
        return fib(n-1)+fib(n-2);
    }
}