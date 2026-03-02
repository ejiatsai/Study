#include <stdio.h>
#include <stdlib.h>

typedef struct process{
    int time;
    char name[11];
    struct process *next;
}Process;

int main(){
    int n = 0,q = 0,sum_of_time = 0;
    scanf("%d",&n);
    scanf("%d",&q);
    Process *head = (Process *)malloc(sizeof(Process));
    scanf("%s",head -> name);
    scanf("%d",&head -> time);
    head -> next = NULL;
    Process *current = head;
    for(int i = 1;i < n;i++){
        current -> next = (Process *)malloc(sizeof(Process));
        current = current -> next;
        scanf("%s",current -> name);
        scanf("%d",&current -> time);
        current -> next = NULL;
    }
    current -> next = head;
    Process *prev = current;
    Process *target = head;
    while(n > 0){
        if(target -> time > q){
            target -> time -= q;
            sum_of_time += q;
            prev = target;
            target = target -> next;
        }
        else{
            sum_of_time += target -> time;
            printf("%s %d\n",target -> name,sum_of_time);
            prev -> next = target -> next;
            free(target);
            target = prev -> next;
            n--;
        }
    }
    return 0;
}