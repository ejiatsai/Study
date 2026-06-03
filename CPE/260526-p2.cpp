#include <bits/stdc++.h>
using namespace std;

int main(){
    int M = 0,N = 0;
    char c[100][100];
    int dr[8] = { 1,1,-1,-1,1,-1,0,0 };
    int dc[8] = { 1,-1,1,-1,0,0,1,-1 };
    int SC = 1;
    while(1){
        cin >> M >> N;
        if(M == 0 && N == 0){
            break;
        }
        if(SC != 1){
            cout << endl;
        }
        for(int i = 0;i < M;i++){
            for(int j = 0;j < N;j++){
                cin >> c[i][j];
            }
        }
        cout << "Field " << SC << ":\n";
        for(int i = 0;i < M;i++){
            for(int j = 0;j < N;j++){
                if(c[i][j] == '*'){
                    cout << "*";
                }
                else{
                    int count = 0;
                    for(int d = 0;d < 8;d++){
                        if(i + dr[d] >= 0 && i + dr[d] < M && j + dc[d] >= 0 && j + dc[d] < N){
                            if(c[i + dr[d]][j + dc[d]] == '*'){
                                count++;
                            }
                        }
                    }
                    cout << count;
                }
            }
            cout << endl;
        }
        SC++;
    }
}