//
// Created by Maksim Kuzin on 12/7/25.
//

#ifndef MIPT_C_LABS_TIMER_H
#define MIPT_C_LABS_TIMER_H

#include <chrono>

class Timer {
public:
    Timer();                       // конструктор
    unsigned long long GetTime();  // метод получения интервала

private:
    std::chrono::high_resolution_clock::time_point old_time;
};


#endif //MIPT_C_LABS_TIMER_H