#include <iostream>
#include <sstream>
#include <vector>

std::string parse_func(std::string s,std::vector <std::string>  *v){
    std::string cur;
    for(char ch:s){
        if(ch == '(' || ch == ')' || ch == ','){
            if(!cur.empty()) {
                v->push_back(cur);
                cur.clear();
            }
        }
        else{
            cur += ch;
        }
    }
}

int main(){
    std::vector <std::string> token;
    std::string function;
    std::cin >> function;
    parse_func(function,&token);
    std::cout << "Tokens:[";
    for(auto it:token){
        std::cout << "\"" << it << "\",";
    }
    std::cout << "]";
    return 0;
}