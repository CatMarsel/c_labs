//
// Created by Maksim Kuzin on 12/8/25.
//

#ifndef MIPT_C_LABS_RANDOMARRAY_H
#define MIPT_C_LABS_RANDOMARRAY_H
#include "Random.h"

class RandomArray {
public:
    explicit RandomArray(unsigned max_value = 1'000'000);  // аналог INT_MAX
    void Fill(unsigned* arr, unsigned n);                  // аналог RandomizeArray()

private:
    Random rnd;     // объект генератора случайных чисел
};


#endif //MIPT_C_LABS_RANDOMARRAY_H