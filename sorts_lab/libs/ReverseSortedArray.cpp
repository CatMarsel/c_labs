//
// Created by Maksim Kuzin on 12/8/25.
//

#include "ReverseSortedArray.h"

void ReverseSortedArray::Fill(unsigned* arr, unsigned n) {
    for (unsigned i = 0; i < n; i++) {
        arr[i] = n - 1 - i;  // обратная последовательность
    }
}