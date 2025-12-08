//
// Created by Maksim Kuzin on 12/8/25.
//

#include "SortedArray.h"
void SortedArray::Fill(unsigned* arr, unsigned n) {
    for (unsigned i = 0; i < n; i++) {
        arr[i] = i;   // строго возрастающая последовательность
    }
}