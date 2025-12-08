//
// Created by Maksim Kuzin on 12/7/25.
//

#include "Timer.h"

// конструктор: сохраняем текущее время
Timer::Timer()
    : old_time(std::chrono::high_resolution_clock::now())
{}

// метод GetTime: возвращает интервал в наносекундах
unsigned long long Timer::GetTime() {
    auto new_time = std::chrono::high_resolution_clock::now();
    unsigned long long result =
        std::chrono::duration_cast<std::chrono::nanoseconds>(new_time - old_time).count();
    old_time = new_time;
    return result;
}