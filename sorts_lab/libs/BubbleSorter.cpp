//
// Created by Maksim Kuzin on 12/8/25.
//

#include "BubbleSorter.h"

void BubbleSorter::Sort(unsigned* arr, unsigned n) {
    for (unsigned i = 0; i < n - 1; i++) {
        for (unsigned j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                unsigned t = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = t;
            }
        }
    }
}