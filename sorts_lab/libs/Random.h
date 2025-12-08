//
// Created by Maksim Kuzin on 12/7/25.
//

#ifndef MIPT_C_LABS_RANDOM_H
#define MIPT_C_LABS_RANDOM_H
#include <random>
#include <chrono>

class Random {
public:
    Random(int min, int max);   // диапазон
    int Next();                 // сгенерировать число

private:
    std::default_random_engine engine;
    std::uniform_int_distribution<int> dist;
};
#endif //MIPT_C_LABS_RANDOM_H