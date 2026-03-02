#include <stdio.h>

int isprime(int x);

int main() {
    int n;
  
    while(scanf("%d", &n)!=EOF) {
        if(isprime(n) == 1) puts("prime");
        else puts("not prime");
    }
  
  return 0;
}

int isprime(int x){
    if(x == 0 || x == 1) {
        return 0;
    }
    else {
        for(int i = 2;i*i <= x;i++){
            if(x % i == 0){
                return 0;
            }
        }
    }
    return 1;
}