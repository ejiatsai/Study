#include <stdio.h>
#include <string.h>

void replace(char *rep,char *str,int a,int b);
void reverse(char *str,int a,int b);

int main(){
    char str[1000] = {'\0'};
    scanf("%s",str);
    int q = 0;
    scanf("%d",&q);
    char request[10] = {'\0'};
    for(int i = 0;i < q;i++){
        int a = 0,b = 0;
        scanf("%s",request);
        if(strcmp(request,"replace") == 0){
            scanf("%d",&a);
            scanf("%d",&b);
            char rep[1000] = {'\0'};
            scanf("%s",rep);
            replace(rep,str,a,b);
        }
        else if(strcmp(request,"reverse") == 0){
            scanf("%d",&a);
            scanf("%d",&b);
            reverse(str,a,b);
        }
        else if(strcmp(request,"print") == 0){
            scanf("%d",&a);
            scanf("%d",&b);
            for(int i = a;i <= b;i++){
                printf("%c",str[i]);
            }
            printf("\n");
        }
    }
}

void replace(char *rep,char *str,int a,int b){
    int tmp = 0;
    for(int i = a;i <= b;i++){
        str[i] = rep[tmp];
        tmp++;
    }
}

void reverse(char *str,int a,int b){
    while(a < b){
        char tmp = str[a];
        str[a] = str[b];
        str[b] =  tmp;
        a++;
        b--;
    }
}