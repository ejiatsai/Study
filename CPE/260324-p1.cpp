#include <bits/stdc++.h>
using namespace std;

int HappyNumber(int N){
    int sum = 0;
    set <int> seen;
    vector <int> Sum;
    while(N != 1){
        sum = 0;
        int tmp = 1;
        if(seen.count(N)){
            return 0;
        }
        seen.insert(N);
        while(N / tmp != 0){
            Sum.push_back(N / tmp % 10);
            tmp *= 10;
        }
        for(auto it:Sum){
             sum += it*it;
        }
        N = sum;
        Sum.clear();
    }
    if(N == 1){
        return 1;
    }
}

int main(){
    int Case = 0;
    cin >> Case;
    int N = 0;
    vector <int> Num;
    for(int i = 0;i < Case;i++){
        cin >> N;
        Num.push_back(N);
    }
    for(int i = 0;i < Case;i++){
        if(HappyNumber(Num[i])){
            cout << "Case #" << i + 1 << ": " << Num[i] << " is a Happy number.\n";
        }
        else{
            cout << "Case #" << i + 1 << ": " << Num[i] << " is an Unhappy number.\n";
        }
    }
    return 0;
}