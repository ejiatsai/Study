#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>

class Showable {
    public:
        virtual std::string toString() const = 0;
        virtual ~Showable() {}
};

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

class InftyA : public Showable{
private:
    int val;                                 // 當前數值
    int trans(int x){return x+1;}            // 轉換函數
    std::string nxt_str;                          // 下一個狀態的建構字串

public:
    // 一般建構子
    InftyA(int v) : val(v) {
        // 調用 trans 計算結果 v_
        nxt_str = "InftyA(" + std::to_string(trans(val)) + ")";
    }

    // 從字串建構
    InftyA(const std::string& str) {
        // 調用 fromStr ，使用等號運算子賦值給當前物件
        *this = fromStr(str);
    }

    // 實作 Readable 概念
    InftyA fromStr(const std::string& str) {
        std::vector <std::string> token;
        parse_func(str,&token);
        if(token.size() == 2 && token[0] == "InftyA"){
            int v = std::stoi(token[1]);
            return InftyA(v);
        }
        else {
            throw std::runtime_error("");
        }
        // 調用前面作業的 parse_func 計算出 tokens
        // 比較 tokens[0] 是否為正確資料型態(類名稱)
        // 計算 tokens[1] 為參數 v
        // 調用建構子並回傳
    }

    // Showable
    std::string toString() const override{
        return "InftyA(" + std::to_string(val) + ")";
    }

    // 取得當前數值
    int getVal() const { return val; }

    // 評估下一個狀態並更新自身
    void eval() {
        *this = InftyA(nxt_str);
        // 藉由建構子從 nxt_str 字串建構下一個物件
        // 複製賦值
    }
};

int main() {
    try {
        // 從字串建構物件
        InftyA a(5);
        std::cout << a.toString() << std::endl;   // InftyA(5)
        a.eval();
        std::cout << a.toString() << std::endl;   // InftyA(6)


        // 重載藉由字串轉換
        InftyA b("InftyA(3)");
        std::cout << b.toString() << std::endl;   // InftyA(3)
        b.eval();
        std::cout << b.toString() << std::endl;   // InftyA(4)

        // 驗證逆運算
        InftyA c(InftyA(6).toString());
        std::cout << c.toString() << std::endl;   // InftyA(6)
        c.eval();
        std::cout << c.toString() << std::endl;   // InftyA(7)

        // 拋出錯誤
        InftyA d("InftyA(10, 1)");
    } catch (const std::exception& e) {
        std::cerr << "ERROR" << e.what() << std::endl;
    }
    // 應能處理錯誤並繼續此處的待碼
    std::cout << "Bye." << std::endl;
    return 0;
}
