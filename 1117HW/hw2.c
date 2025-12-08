#include <stdio.h>
#include <string.h>

void add(char *fint,char *sint,char *sum);

int main(void){
    int n = 0;
    scanf("%d",&n);
    for(int i = 0;i < n;i++){
        char fint[105] = {'\0'},sint[105] = {'\0'},sum[105] = {'\0'};
        scanf("%s",fint);
        scanf("%s",sint);
        add(fint,sint,sum);
    }
}

void add(char *fint,char *sint,char *sum){
    int a = strlen(fint) - 1;
    int b = strlen(sint) - 1;
    int carry = 0;
    int count = 0;
    while(a >= 0 || b >= 0){
        int x = 0,y = 0;
        if(a >= 0){
            x = fint[a] - '0';
        }
        if(b >= 0){
            y = sint[b] - '0';
        }
    sum[count] = (x + y + carry) % 10 + '0';
    carry = (x + y + carry) / 10;
    count++;
    a--;
    b--;
    }
    if(carry == 1){
        sum[count] = '1';
        count++;
    }
    if(count > 80){
        printf("overflow");
    }
    else {
        for(int i = count - 1;i >= 0;i--){
            printf("%c",sum[i]);
        }
    }
    printf("\n");
}