//
// Created by Maksim Kuzin on 12/8/25.
//

#include "SelectionSorter.h"

void SelectionSorter::Sort(unsigned* arr, unsigned n) {
    for (unsigned i = 0; i < n; i++) {

        // индекс минимального элемента в неотсортированной части
        unsigned minIndex = i;

        // ищем минимум
        for (unsigned j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        // если нашли меньший — меняем местами
        if (minIndex != i) {
            unsigned t = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = t;
        }
    }
}