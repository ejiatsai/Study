#include <stdio.h>

int RT(int x,int y,int z);
int RTS(int d,int e,int f);

int main(void){
    int n = 0,a = 0,b = 0,c = 0;
    scanf("%d",&n);
    for(int i = 0;i < n;i++){
        scanf("%d %d %d",&a,&b,&c);
        if(RT(a,b,c) == 1) puts("YES");
        else puts("NO");
    }
}

int RT(int  x,int y,int z){
    if(RTS(x,y,z)  == 1 || RTS(y,z,x) == 1 || RTS(x,z,y) == 1) return 1;
    else return 0;
}

int RTS(int d,int e,int f){
    if(d * d + e * e == f * f) return 1;
    else return 0;
}
