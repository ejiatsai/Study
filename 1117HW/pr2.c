#include <stdio.h>
#define SIZE 100

int search(const char *str,const char *key);

int main(){
    char str[SIZE],key[SIZE];

    scanf("%s%s",str,key);

    printf("%d\n",search(str,key));
}

int search(const char *str,const char *key){
    int count = 0;
    for(char *i = str;*i != '\0';i++){
        char *stmp = i;
        char *ktmp = key;
        while (*stmp == *ktmp && *ktmp != '\0') {
            stmp++;
            ktmp++;
        }

        if (*ktmp == '\0') {
            count++;
        }
    }
    return count;    
}