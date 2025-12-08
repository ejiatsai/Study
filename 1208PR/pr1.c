#include <stdio.h>
#include <string.h>

typedef struct contact{
    char name[105][20];
    char phone[105][11];
}contact;

int main(){
    contact Contact;
    int i = 0;
    while(1){
        scanf("%s",Contact.name[i]);
        scanf("%s",Contact.phone[i]);
        if(strcmp(Contact.name[i],"0") == 0 && strcmp(Contact.phone[i],"0") == 0){
            break;
        }
        i++;
    }
    puts("--");
    char action;
    while(1){
        printf("(s) show\n");
        printf("(l) lookup\n");
        printf("(n) sort by name\n");
        printf("(p) sort by phone\n");
        printf("Chose your action:");
        scanf(" %c",&action);
        puts("--");
        if(action == '0'){
            break;
        }
        if(action == 's'){
            for(int j = 0;j < i;j++){
                printf("%s, %s",Contact.name[j],Contact.phone[j]);
                printf("\n");
            }
        }
        else if(action == 'l'){
            char Search_phone[11];
            scanf("%s",Search_phone);
            for(int j = 0;j < i;j++){
                if(strcmp(Contact.phone[j],Search_phone) == 0){
                    printf("%s\n",Contact.name[j]);
                }
            }
        }
        else if(action == 'n'){
            
        }
        else {

        }
        puts("--");
    }
}