#include <stdio.h>
#include <ctype.h>
#define SIZE 10000

int main(){
    char str[SIZE];
    int count[26] = {0};
    char ch;
    while((ch = getchar()) != EOF){
        ch = tolower(ch);
        if(ch >= 'a' && ch <= 'z'){
            count[ch - 'a']++;
        }
    }
    for(int i = 0; i < 26; i++){
        printf("%c : %d\n",'a' + i,count[i]);
    }
}