#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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
            puts("--");
        }
        else if(action == 'l'){
            char Search_phone[11];
            int count = 0;
            scanf("%s",Search_phone);
            for(int j = 0;j < i;j++){
                if(strcmp(Contact.phone[j],Search_phone) == 0){
                    printf("%s\n",Contact.name[j]);
                    break;
                }
                count++;
            }
            if(count == i){
                printf("This phone number does not exist\n");
            }
            puts("--");
        }
        else if(action == 'n'){
            char tmp_name[20];
            char tmp_phone[11];
            for(int x = 0;x < i - 1;x++){
                for(int y = 0;y < i - 1 - x;y++){
                    if(strcmp(Contact.name[y],Contact.name[y + 1]) > 0){
                        strcpy(tmp_name,Contact.name[y]);
                        strcpy(tmp_phone,Contact.phone[y]);
                        strcpy(Contact.name[y],Contact.name[y + 1]);
                        strcpy(Contact.phone[y],Contact.phone[y + 1]);
                        strcpy(Contact.name[y + 1],tmp_name);
                        strcpy(Contact.phone[y + 1],tmp_phone);
                    }
                }
            }
        }
        else if(action == 'p'){
            char tmp_name[20];
            char tmp_phone[11];
            for(int x = 0;x < i - 1;x++){
                for(int y = 0;y < i - 1 - x;y++){
                    if(strcmp(Contact.phone[y],Contact.phone[y + 1]) > 0){
                        strcpy(tmp_name,Contact.name[y]);
                        strcpy(tmp_phone,Contact.phone[y]);
                        strcpy(Contact.name[y],Contact.name[y + 1]);
                        strcpy(Contact.phone[y],Contact.phone[y + 1]);
                        strcpy(Contact.name[y + 1],tmp_name);
                        strcpy(Contact.phone[y + 1],tmp_phone);
                    }
                }
            }
        }
        else {
            printf("This is wrong action\n");
            puts("--");
        }
    }
}