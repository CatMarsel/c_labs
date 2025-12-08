//
// Created by Maksim Kuzin on 12/8/25.
//

#include "ShakerSorter.h"

void ShakerSorter::Sort(unsigned* arr, unsigned n) {
    if (n <= 1) return;

    unsigned left = 0;
    unsigned right = n - 1;

    while (left < right) {
        // Проход слева направо
        for (unsigned i = left; i < right; i++) {
            if (arr[i] > arr[i + 1]) {
                unsigned t = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = t;
            }
        }
        right--;

        // Проход справа налево
        for (unsigned i = right; i > left; i--) {
            if (arr[i - 1] > arr[i]) {
                unsigned t = arr[i - 1];
                arr[i - 1] = arr[i];
                arr[i] = t;
            }
        }
        left++;
    }
}