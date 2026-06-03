#include <iostream>
#include <thread>
#include <vector>
#include <chrono>
#include <string>
#include <atomic>
#include <mutex>

using namespace std;

// ---------- 共用變數 ----------
atomic<int>  sec{0};                // 秒計數器
atomic<bool> print_flag{false};     // 輸出狀態
vector<string> msg_list;            // 暫存使用者輸入的字串（改名避免衝突）

atomic<bool> running{true};         // 控制所有線程

mutex mtx;

// 記錄上次輸入的時間
atomic<chrono::steady_clock::time_point> last_input_time{chrono::steady_clock::now()};

// ---------- 線程1：計時器 ----------
void timer_thread() {
    while (running) {
        this_thread::sleep_for(chrono::seconds(1));

        if (running) {
            sec++;
        }/* HW */ // 計時器控制 (時間流動);
    }
}

// ---------- 線程2：空閒提醒 ----------
void idle_check_thread() {
    while (running) {
        this_thread::sleep_for(chrono::seconds(1));
        if (!running) break;

        auto now = chrono::steady_clock::now();
        auto last = last_input_time.load();
        auto diff = chrono::duration_cast<chrono::seconds>(now - last).count();
        /* HW */
        if (diff >= 5) {
            lock_guard<mutex> lock(mtx);
            cout << "\n[alert]: haven't enter message in 5 seconds";
            // 按照格式印出訊息
            // ...
            last_input_time.store(now);  // 重置計時起點，避免連續提醒
        }
    }
}

// ---------- 線程3：記錄與輸出 ----------
void recorder_thread() {
    while (running) {
        this_thread::sleep_for(chrono::seconds(1));
        if (!running) break;

        int s = sec.load();

        lock_guard<mutex> lock(mtx);

        // 如果 print_flag 為 false 且 msg_list 有資料 → 輸出
        if (!print_flag.load() && !msg_list.empty()) {
            cout << "\n[" << s << "sec]:\n";
            for(const auto& msg : msg_list){
                cout << msg << "\n";
            }
            /* HW */
            // 按照格式印出訊息
            // ...
            print_flag.store(true);   // 通知主程式清空
        } else {
            cout << "\n[" << s << "sec]: (no msg)\n";
        }
    }
}

// ---------- 主程式 ----------
int main() {
    cout << "Enter text(input `quit` to exit):\n";

    thread t1(timer_thread);
    thread t2(idle_check_thread);
    thread t3(recorder_thread);
    /* HW */
    // 啟動三個線程
    // ...

    string input;
    while (running) {
        getline(cin, input);
        if (input == "quit") break;

        // 更新最後輸入時間
        last_input_time.store(chrono::steady_clock::now());

        // 如果 print_flag 為 true → 上一批訊息已輸出，清空 msg_list
        if (print_flag.load()) {
            msg_list.clear();
            print_flag.store(false); // 重置 flags
        }

        msg_list.push_back(input);
        /* HW */
        // 儲存新的輸入至vector
    }

    // 結束所有線程
    running.store(false);

    t1.join();
    t2.join();
    t3.join();
    /* HW */
    // 等待所有線程結束
    // ...
    return 0;
}