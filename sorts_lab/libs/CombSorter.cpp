//
// Created by Maksim Kuzin on 12/8/25.
//

#include "CombSorter.h"

void CombSorter::Sort(unsigned* arr, unsigned n) {
    if (n <= 1) return;

    // начальный шаг – весь массив
    unsigned gap = n;
    bool swapped = true;

    while (gap > 1 || swapped) {
        // уменьшаем шаг
        gap = static_cast<unsigned>(gap / 1.3);
        if (gap < 1)
            gap = 1;

        swapped = false;

        // проходим массив с данным шагом
        for (unsigned i = 0; i + gap < n; i++) {
            if (arr[i] > arr[i + gap]) {
                unsigned t = arr[i];
                arr[i] = arr[i + gap];
                arr[i + gap] = t;
                swapped = true;
            }
        }
    }
}
