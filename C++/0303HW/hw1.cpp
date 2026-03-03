#include <iostream>
#include <vector>

int main(){
    int a = 0;
    std::vector <int> v;
    while(std::cin >> a && a != -1){
        v.push_back(a);
    }
    for(int i = 0;i < v.size();i++){
        std::cout << v[i] << " ";
        while(1){
            if(v[i] == 1){
                break;
            }
            else if(v[i] % 2 != 0){
                v[i] = v[i] * 3 + 1;
                std::cout << v[i] << " ";
            }
            else{
                v[i] /= 2;
                std::cout << v[i] << " ";
            }
            
        }
        std::cout << std::endl;
    }
}
