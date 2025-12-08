#include <stdio.h>
#define MAXN 100005

int main(){
    int n = 0, q = 0;
    char Process_name[MAXN][11] = {'\0'};
    int Process_time[MAXN] = {'\0'};
    int Sum_of_time = 0;
    int Num_of_downprocess = 0;
    scanf("%d", &n);
    scanf("%d", &q);
    int Process_id[MAXN] = {'\0'};
    for(int i = 0; i < n; i++){
        scanf("%s", Process_name[i]);
        scanf("%d", &Process_time[i]);
        Process_id[i] = i;
    }
    int head = 0,tail = n - 1;
    while(Num_of_downprocess < n){
        if(Process_time[Process_id[head]] > q){
            Process_time[Process_id[head]] -= q;
            head = (head + 1) % n;
            tail = (tail + 1) % n;
            Sum_of_time += q;
        }
        else{
            Sum_of_time += Process_time[Process_id[head]];
            printf("%s %d\n", Process_name[Process_id[head]], Sum_of_time);
            head = (head + 1) % n;
            Num_of_downprocess++;
        }
    }
}