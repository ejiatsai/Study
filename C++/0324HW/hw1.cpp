#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <vector>

class Showable {
    public:
        virtual std::string toString() const = 0;
        virtual ~Showable() {}
};

class People : public Showable{
protected:
    int healthPoint;
    int location;
    int speed;
    int direction;
    int attackPoint;

public:
    People(int hp, int loc, int sp, int drt, int atk) {
        healthPoint = hp;
        location = loc;
        speed = sp;
        attackPoint = atk;
        if (drt > 0) direction = 1;
        else direction = -1;
    }

    virtual ~People() = default;

    int getLocation() const { return location; }

    void setLocation() {
        location = (rand() % 41) - 20;
    }

    bool isAlive() const { return healthPoint > 0; }

    virtual void move(People *p) {
        location += speed * direction;
    }

    virtual void hurt(int damage) {
        healthPoint -= damage;
        if(healthPoint < 0){
            healthPoint = 0;
        }
    }

    virtual void attack(People* p) {
        p->hurt(attackPoint);
    }

    int getHealth() const { return healthPoint; }

    void roundend(int endhp) {
        healthPoint -= endhp;
    }

    std::string toString() const override{
        std::string dir = "";
        if(direction > 0){
            dir = "+";
        }
        else{
            dir = "-";
        }
        return "<HP: " + std::to_string(healthPoint) + ", Atk: " + std::to_string(attackPoint) + ", SP: " + std::to_string(speed) + ", POS(D): " + std::to_string(location) + "(" + dir + ")>";
    }

    People& operator++(){
        this->healthPoint += 5;
        return *this;
    }

    People operator--(){
        this->healthPoint -= 3;
        return *this;
    }
};

class Warrior : public People{
public:

    Warrior(int hp, int loc, int sp ,int drt, int atk):
        People(hp,loc,sp,drt,atk) {}
    
    void move(People *p) override {
        int p2_location = p->getLocation();
        if(location - p2_location > 0){
            direction = -1;
        }
        else {
            direction = 1;
        }
        if(abs(location - p2_location) > speed){
            location += speed * direction;
        }
        else if(location - p2_location == 0){
            location += 0;
        }
        else {
            location += (abs(location - p2_location) - 1) * direction;
        }
    }

    void hurt(int damage) override {
        healthPoint -= 0.7*damage;
        if(healthPoint < 0){
            healthPoint = 0;
        }
    }

    void attack(People* p) override {
        if(abs(location - p->getLocation()) <= 1){
            p->hurt(attackPoint);
        }
        else {
            std::cout << "距離過遠，無法攻擊" << "\n";
        }
    }

    std::string toString() const override{
        std::string dir = "";
        if(direction > 0){
            dir = "+";
        }
        else{
            dir = "-";
        }
        return "戰士:<HP: " + std::to_string(healthPoint) + ", Atk: " + std::to_string(attackPoint) + ", SP: " + std::to_string(speed) + ", POS(D): " + std::to_string(location) + "(" + dir + ")>";
    }
};


class Archer : public People{
public:
    Archer(int hp, int loc, int sp,int drt, int atk) :
        People(hp,loc,sp,drt,atk) {}

    void move(People *p) override {
        int p2_location = p->getLocation();
        if(location - p2_location > 0){
            direction = -1;
        }
        else {
            direction = 1;
        }
        location += -1 * speed * direction;
    }

    void attack(People* p) override {
        if(abs(location - p->getLocation()) <= 15){
            p->hurt(attackPoint);
        }
        else {
           std::cout << "距離過遠，無法攻擊" << "\n";
        }
    }

    std::string toString() const override{
        std::string dir = "";
        if(direction > 0){
            dir = "+";
        }
        else{
            dir = "-";
        }
        return "弓手:<HP: " + std::to_string(healthPoint) + ", Atk: " + std::to_string(attackPoint) + ", SP: " + std::to_string(speed) + ", POS(D): " + std::to_string(location) + "(" + dir + ")>";
    }
};

void printObject(const Showable* obj){
    std::cout << obj->toString() << std::endl;
}

void recover(People *p){
    ++(*p);
}

void fatigue(People *p){
    --(*p);
}

int battle(People* p1, People* p2) {
    int round = 1;
    std::cout << "\n===== Player1 =====\n";
    p1->setLocation();
    printObject(p1);
    std::cout << "\n===== Player2 =====\n";
    p2->setLocation();
    printObject(p2);
    while (p1->isAlive() && p2->isAlive()) {
        std::cout << "\n===== 第 " << round << " 回合 =====\n";
        if(round > 20){
            int endhp = 0;
            if(p1->getHealth() > p2->getHealth()){
                endhp = p2->getHealth();
            }
            else{
                endhp = p1->getHealth();
            }
            p1->roundend(endhp);
            p2->roundend(endhp);
            std::cout << "Player1 剩餘血量：" << p1->getHealth() << "\n";
            std::cout << "Player2 剩餘血量：" << p2->getHealth() << "\n";
            if(!p1->isAlive() && !p2->isAlive()){
                std::cout << "Player1 已被擊敗;Player2 已被擊敗\n";
                break;
            }
            else if (!p1->isAlive()) {
                std::cout << "Player1 已被擊敗！\n";
                break;
            }
            else if(!p2->isAlive()){
                std::cout << "Player2 已被擊敗！\n";
                break;
            }
        }
        if(round % 4 == 0){
            std::cout << "觸發回血\n";
            recover(p1);
            recover(p2);
        }
        if(round > 10){
            std::cout << "戰鬥超過10回合,每回合減少3生命\n";
            fatigue(p1);
            fatigue(p2);
        }
        // p1 的回合：先移動，再攻擊 p2
        std::cout << "Player1 移動前位置：" << p1->getLocation();
        p1->move(p2);
        std::cout << "，移動後位置：" << p1->getLocation() << "\n";
        p1->attack(p2);
        std::cout << "Player2 剩餘血量：" << p2->getHealth() << "\n";
        if (!p2->isAlive()) {
            std::cout << "Player2 已被擊敗！\n";
            break;
        }

        // p2 的回合：先移動，再攻擊 p1
        std::cout << "Player2 移動前位置：" << p2->getLocation();
        p2->move(p1);
        std::cout << "，移動後位置：" << p2->getLocation() << "\n";
        p2->attack(p1);
        std::cout << "Player1 剩餘血量：" << p1->getHealth() << "\n";
        if (!p1->isAlive()) {
            std::cout << "Player1 已被擊敗！\n";
            break;
        }

        round++;
    }

    // 輸出勝利者
    if(!p1->isAlive() && !p2->isAlive()){
        std::cout << "平局!\n";
        return -1;
    }
    else if (p1->isAlive()){
        for(int i = 0;i < 5;i++){
            recover(p1);
        }
        std::cout << "\n>>> 勝利者是 Player1! 回復25點血!<<<\n";
        return 1;
    }
    else if(p2->isAlive()){
        for(int i = 0;i < 5;i++){
            recover(p2);
        }
        std::cout << "\n>>> 勝利者是 Player2! 回復25點血!<<<\n";
        return 0;
    }
}

int main() {
    srand(time(NULL));
    std::vector <People *> teamA;
    std::vector <People *> teamB;
    std::string c;
    std::cout << "===== Enter w to add a warrior;enter a to add a archer =====\n" << "Team A:\n";
    for(int i = 0;i < 6;i++){
        std::cin >> c;
        if(c == "w"){
            teamA.push_back(new Warrior(100, 0, 6,1, 20)); // sp,loc0,sp,drt,atk
        }
        else {
            teamA.push_back(new Archer(80, 0, 4,1, 15)); // sp,loc,sp,drt,atk
        }
    }
    std::cout << "===== Enter w to add a warrior;enter a to add a archer =====\n" << "Team B:\n";
    for(int i = 0;i < 6;i++){
        std::cin >> c;
        if(c == "w"){
            teamB.push_back(new Warrior(100, (rand() % 41) - 20, 6,1, 20));
        }
        else {
            teamB.push_back(new Archer(80, (rand() % 41) - 20, 4,1, 15));
        }
    }
    auto teamAptr = teamA.begin();
    auto teamBptr = teamB.begin();
    int teamAwin = 0,teamBwin = 0;
    while(teamAptr != teamA.end() && teamBptr != teamB.end()){
        int result = battle(*teamAptr,*teamBptr);
        if(result == -1){
            teamAptr++;
            teamBptr++;
        }
        else if(result == 1){
            teamBptr++;
            teamAwin++;
        }
        else if(result == 0){
            teamAptr++;
            teamBwin++;
        }
    }
    std::cout << "The round team A wins:" << teamAwin << std::endl;
    std::cout << "The round team B wins:" << teamBwin << std::endl;
    if(teamAwin > teamBwin){
        std::cout << "Team A is winner" << std::endl;
    }
    else if(teamAwin < teamBwin){
        std::cout << "Team B is winner" << std::endl;
    }
    else {
        std::cout << "It's a tie";
    }
    for (People* p : teamA){
        delete p; // release memory
    }
    for (People* p : teamB){
        delete p; // release memory
    }
    teamA.clear();
    teamB.clear();
    return 0;
}