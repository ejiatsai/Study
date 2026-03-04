#include<iostream>
#include<vector>

class CollatzExp
{
    public:
        void run(void);
        void runStep(void);
        void showSeq(void);
        int getStep(int);
        int* getSeq(void);
        void reset(int);
        CollatzExp(int); // 建構子
    private:
        int baseNum;
        int cur_num;
        std::vector<int> v;
        int step_counter;
        int finish_flag;
};

CollatzExp::CollatzExp(int n){
        baseNum = n;
        cur_num = baseNum;
        step_counter = 0;
        finish_flag = 0;
}

void CollatzExp::runStep(void){
    int n = cur_num;
    if(cur_num!=1){
        v.push_back(n);
        cur_num = (n%2==0)?n/2:3*n+1;
        step_counter += 1;
    }
    else {
        v.push_back(1);
        finish_flag = 1; // 推演結束
    }
}

void CollatzExp::run(void){
    while(!finish_flag) runStep();
}

void CollatzExp::showSeq(void){
    if(!finish_flag)
        std::cout <<"未完成"<< std::endl;
    int *arr = v.data();
    while(*arr != 1) {
        std::cout << *arr << " ";
        arr++;
    }
    std::cout << 1 << std::endl;
}

int CollatzExp::getStep(int s){
    if(!finish_flag)
        std::cout <<"未完成"<< std::endl;
    if(s > step_counter){
        std::cout << "不存在的步驟" << std::endl;
    }  
    else{
        std::cout << v[s] << std::endl;
    } 
        
}

void CollatzExp::reset(int n){
    v.clear();
    baseNum = n;
    cur_num = baseNum;
    step_counter = 0;
    finish_flag = 0;
    while(!finish_flag) runStep();
}

int main(){
    // 完成 W2-3 最後的作業
    int num = 0,step = 0;
    std::cin >> num;
    CollatzExp col = CollatzExp(num);
    col.run();
    col.showSeq();
    std::cin >> step;
    col.getStep(step);
    std::cin >> num;
    col.reset(num);
    col.showSeq();
    std::cin >> step;
    col.getStep(step);
    return 0;
}
