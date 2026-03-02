#include <stdio.h>

int main(){
    int n = 0, q = 0;
    char Process_name[100000][11] = {'\0'};
    int Process_time[100000] = {'\0'};
    int Sum_of_time = 0;
    int Num_of_downprocess = 0;
    scanf("%d", &n);
    scanf("%d", &q);
    for(int i = 0; i < n; i++){
        scanf("%s", Process_name[i]);
        scanf("%d", &Process_time[i]);
    }
    int Process_count = 0;
    while(Num_of_downprocess < n){
        if(Process_time[Process_count] == 0){
            Process_count = (Process_count + 1) % n;
            continue;
        }
        if(Process_time[Process_count] > q){
            Process_time[Process_count] -= q;
            Sum_of_time += q;
        }
        else{
            Sum_of_time += Process_time[Process_count];
            printf("%s %d\n", Process_name[Process_count], Sum_of_time);
            Process_time[Process_count] = 0;
            Num_of_downprocess++;
        }
        Process_count = (Process_count + 1) % n;
    }
}
