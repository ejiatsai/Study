#include <bits/stdc++.h>
using namespace std;

int main(){
    vector <string> g;
    int Case = 0;
    cin >> Case;
    int n = 0,m = 0;
    string s;
    for(int i = 0;i < Case;i++){
        cin >> n >> m;
        for(int i = 0;i < n;i++){
            cin >> s;
            g.push_back(s);
        }
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++){
                tolower(g[i][j]);
            }
        }
        int nameNum = 0;
        cin >> nameNum;
        vector <string> name;
        string Name;
        for(int i = 0;i < nameNum;i++){
            cin >> Name;
            name.push_back(Name);
        }
        for(int i = 0;i < nameNum;i++){
            for(int j = 0;j < name[i].size();j++){
                tolower(name[i][j]);
            }
        }
        
    }
    return 0;
}