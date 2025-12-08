//
// Created by Maksim Kuzin on 12/8/25.
//

#include "RandomArray.h"

RandomArray::RandomArray(unsigned max_value)
    : rnd(0, max_value)     // создаём Random с диапазоном [0, max_value]
{}

void RandomArray::Fill(unsigned* arr, unsigned n) {
    for (unsigned i = 0; i < n; i++) {
        arr[i] = rnd.Next();   // генерируем число через класс Random
    }
}