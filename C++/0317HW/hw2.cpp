#include <iostream>
#include <cmath>
/* 作業2: 一個簡單的遊戲
 * 這個作業中包含一個基類 People
 * 這個 People 會受傷、會攻擊、會根據方向移動位置
 * 我們要創造兩個類繼承 People
 * 分別是 戰士 Warrior
 * 和弓手 Archer
 * 戰士比較不容易受傷，移動速度比較快，向著面前移動，但只能攻擊眼前的人
 * 弓手正常受傷，移動速度比較慢，向後面移動，可以攻擊遠距離的人
 * 
 * 這兩個類都可以在應用了多型的 battle 函數中進行格鬥遊戲
 * 具體而言這個格鬥遊戲會調用移動、受傷、攻擊等源自於 People 的函數
 *
 * 這次作業的目標
 * 1. 實現 Warrior 與 Archer 的繼承與方法重寫(Override)實作
 * 2. 實現在 People 中 Warrior 與 Archer 的多型，包含基類 virtual, 重寫...
 * 3. 確定程式可以正確執行
 */

using namespace std;

class People {
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
            cout << "距離過遠，無法攻擊" << "\n";
        }
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
            cout << "距離過遠，無法攻擊" << "\n";
        }
    }
};

// 使用多型，接收兩個 People 指標，進行對戰直到一方死亡
void battle(People* p1, People* p2) {
    int round = 1;
    while (p1->isAlive() && p2->isAlive()) {
        cout << "\n===== 第 " << round << " 回合 =====\n";

        // 加分功能 1: 如果兩邊距離太近則不再移動

        // 加分功能 2: 雙方移動方向會隨對方位置改變
        
        // p1 的回合：先移動，再攻擊 p2
        cout << "Player1 移動前位置：" << p1->getLocation();
        p1->move(p2);
        cout << "，移動後位置：" << p1->getLocation() << "\n";
        p1->attack(p2);
        cout << "Player2 剩餘血量：" << p2->getHealth() << "\n";
        if (!p2->isAlive()) {
            cout << "Player2 已被擊敗！\n";
            break;
        }

        // p2 的回合：先移動，再攻擊 p1
        cout << "Player2 移動前位置：" << p2->getLocation();
        p2->move(p1);
        cout << "，移動後位置：" << p2->getLocation() << "\n";
        p2->attack(p1);
        cout << "Player1 剩餘血量：" << p1->getHealth() << "\n";
        if (!p1->isAlive()) {
            cout << "Player1 已被擊敗！\n";
            break;
        }

        round++;
    }

    // 輸出勝利者
    if (p1->isAlive())
        cout << "\n>>> 勝利者是 Player1! <<<\n";
    else
        cout << "\n>>> 勝利者是 Player2! <<<\n";
}

int main() {
    Warrior warrior1(100, 0, 5,1, 20);
    Warrior warrior2(100, 13, 5,1, 20);
    Archer archer(80, 16, 4,1, 15);
    cout << "請選擇:1.戰士 vs 戰士\n" << "       2.戰士 vs 弓手\n";
    int choose = 0;
    cin >> choose;
    if(choose == 1){
        cout << "對戰開始：戰士 vs 戰士\n";
        battle(&warrior1, &warrior2);
    }
    else {
        cout << "對戰開始：戰士 vs 弓手\n";
        battle(&warrior1, &archer);
    }

    return 0;
}